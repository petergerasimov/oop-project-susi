#ifndef __STUDENT_HPP
#define __STUDENT_HPP

#include <string>
#include <vector>
#include <iostream>
#include "mytypes.hpp"

enum Status { interrupted = -1, active, graduated };

/**
* Клас за студент.
*/
class Student
{
    private:
        /**
        * Минимална оценка за взимане на изпит.
        */
        static const int MIN_PASS_GRADE = 3;
        /**
        * Брой на дисциплините, които могат да се влачат.
        */
        static const int MIN_PASSED_COURSES = 2;
        /**
        * Година на завършване.
        */
        static const int GRADUATION_YEAR = 4;
        /**
        * Име на студента.
        */
        std::string name;
        /**
        * Факултетен номер.
        */
        int fn;
        /**
        * Текущ курс.
        */
        int year;
        /**
        * Група на студента.
        */
        int group;
        /**
        * Статус на студента.
        */
        int status;
        /**
        * Име на специалността.
        */
        std::string program;
        /**
        * Низ от дисциплини.
        */
        std::vector< Course > courses;
        /**
        * Метод за намиране на броя невзети изпити.
        * @param mandatory булева - дали да се изключат незадължителните изпити от бройката.
        * @return брой невзети изпити.
        */
        int unpassedCount( bool mandatory = true );
        /**
        * Метод, който връща списък от дисциплините в текущата година.
        * @return масив от дисциплини
        */
        const std::vector< Course >* getCoursesInYear() const;
    public:
        /**
        * Конструктор по подразбиране.
        */
        Student();
        /**
        * Конструктор.
        * @param name име
        * @param fn факултетен номер
        * @param group група
        * @param program име на специалност
        */
        Student( std::string name, int fn, 
                 int group, std::string program );
        /**
        * Деструктор.
        */
        ~Student();
        /**
        * Предефинирана операция за присвояване.
        */
        Student& operator=( const Student& s );
        /**
        * Предефинирана операция за изход.
        */
        friend std::ostream& operator<<(std::ostream &out, const Student &s);
        //Setters
        /**
        * Задава стойност на низа за името на студента.
        * @param name име
        */
        void setName( std::string name );
        /**
        * Задава стойност на променливата за факултетния номер.
        * @param fn факултетен номер
        */
        void setFN( int fn );
        /**
        * Задава стойност на променливата за група.
        * @param group група
        */
        void setGroup( int group );
        /**
        * Задава стойност на променливата за статус.
        * @param status статус
        */
        void setStatus( int status );
        /**
        * Задава стойност на низа за името на специалността.
        * @param program име на специалност
        */
        void setProgram( std::string program );
        /**
        * Задава стойност на променливата за година.
        * @param year година
        */
        void setYear( int year );
        //Getters
        /**
        * Връща името на студента.
        * @return име
        */
        const std::string getName() const;
        /**
        * Връща факултетен номер.
        * @return факултетен номер
        */
        const int getFN() const;
        /**
        * Връща групата на студента.
        * @return факултетен номер.
        */
        const int getGroup() const;
        /**
        * Връща статус на студента.
        * @return статус
        */
        const int getStatus() const;
        /**
        * Връща името на специалността на студента.
        * @return име на специалност
        */
        const std::string getProgram() const;
        /**
        * Връща годината на следване на студента.
        * @return година
        */
        const int getYear() const;
        /**
        * Връща списък от дисциплините, които е записал студента.
        * @return масив от дисциплини
        */
        const std::vector< Course > getCourses() const;
        //
        /**
        * Записва студент. Задава следните параметри.
        * @param name име
        * @param fn факултетен номер
        * @param group група
        * @param program специалност
        */
        void enroll( std::string name, int fn, 
                     int group, std::string program );
        /**
        * Записва студента в следващ курс.
        * @return булева - дали функцията е изпълнена успешно.
        */
        bool advance();
        /**
        * Записва студента в друга група, година или специалност
        * @param option символен низ (program/group/year)
        * @param value (име на специалност/номер на група/година)
        * @return булева - дали функцията е изпълнена успешно.
        */
        bool change( const char* option, const char* value );
        /**
        * Маркира студента като завършил.
        * @return булева - дали функцията е изпълнена успешно.
        */
        bool graduate();
        /**
        * Маркира студента като прекъснал.
        */
        void interrupt();
        /**
        * Маркира студента като активен.
        */
        void resume();
        /**
        * Записва студента в определена дисциплина.
        * @param course име на дисциплина
        * @return булева - дали функцията е изпълнена успешно.
        */
        bool enrollin( const char* course );
        /**
        * Добавя оценка по определена дисциплина.
        * @param course име на дисциплина
        * @param grade оценка
        * @return булева - дали функцията е изпълнена успешно.
        */
        bool addGrade( const char* course, float grade );
        /**
        * Изчислява среден успех.
        * @return среден успех
        */
        const float gradeAverage() const;
        /**
        * Проверява дали студента е записал определена дисциплина.
        * @param course име на дисциплина
        * @return булева - дали студента е записал специалността
        */
        bool isInCourse( const char* course );
        /**
        * Намира броя на записаните дисциплини.
        * @return брой дисциплини
        */
        int numberOfCourses();
        /**
        * Добавя дисциплина в масива от дисциплини.
        * @param course дисциплина (Course)
        */
        void addCourse( const Course& course );
};

#endif //__STUDENT_HPP