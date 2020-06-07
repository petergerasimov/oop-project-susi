#ifndef __SUSI_HPP
#define __SUSI_HPP

#include <vector>
#include <string>
#include "student.hpp"
#include "command.hpp"

/**
* Клас за студентска система.
*/
class Susi
{
    private:
        /**
        * Команда.
        */
        Command c;
        /**
        * Масив от студенти.
        */
        std::vector< Student > students;
        /**
        * Намира студент по факултетен номер.
        * @param fn факултетен номер
        * @return указател към студент
        */
        Student* getStudent( int fn );
        //Files
        /**
        * Име на текущ файл.
        */
        std::string currentFile = "default.dat";
        /**
        * Булева, която следи дали има отворен файл.
        */
        bool isFileOpen;
        /**
        * Чете масив от студенти от файл.
        * @param file път на файла
        */
        void loadFromFile(const char* file);
        /**
        * Записва масив от студенти във файл.
        * @param file път на файла
        */
        void saveToFile(const char* file);
        //Commands
        /**
        * Записва студент в системата.
        * @param fn факултетен номер
        * @param program име на специалността
        * @param group група
        * @param name име на студента
        * @return дали функцията е изпълнена успешно
        */
        bool enroll( int fn, const char* program, int group, const char* name );
        /**
        * Извежда информация за студента.
        * @param fn факултетен номер
        */
        void print( int fn );
        /**
        * Извежда информация за студентите.
        * @param program специалност
        * @param year година
        */
        void printall( const char* program, int year );
        /**
        * Извежда протокол за студентите.
        * @param course дисциплина
        */
        void protocol( const char* course );
        /**
        * Извежда справка за студент.
        * @param fn факултетен номер
        */
        void report( int fn );
        /**
        * Отваря работен файл.
        * @param file път на файла
        * @return дали функцията е изпълнена успешно
        */
        bool open( const char* file );
        /**
        * Затваря работния файл.
        */
        void close();
        /**
        * Запазва текущия работен файл.
        * @return дали функцията е изпълнена успешно
        */
        bool save();
        /**
        * Запазва работен файл.
        * @param file път на файла
        * @return дали функцията е изпълнена успешно
        */
        bool saveAs( const char* file );
        /**
        * Извежда командите в системата.
        */
        void help();
        /**
        * Сортира студенти по факултетен номер.
        * @param toSort масив от студенти
        */
        void sortStudents( std::vector<Student*> &toSort );
    public:
        /**
        * Конструктор.
        */
        Susi();
        /**
        * Деструктор.
        */
        ~Susi();
        /**
        * Същинска логика на програмата.
        * Въвеждат се и се обработват командите.
        * @return дали програмата да продължи да се изпълнява
        */
        bool update();

};

#endif //__SUSI_HPP