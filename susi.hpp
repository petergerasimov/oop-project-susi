#ifndef __SUSI_HPP
#define __SUSI_HPP

#include <vector>
#include <string>
#include "student.hpp"
#include "command.hpp"

class Susi
{
    private:
        //Command
        Command c;
        //Data
        std::vector< Student > students;
        //Helper functions
        Student* getStudent( int fn );
        //Files
        std::string currentFile = "temp.dat";
        void loadFromFile(const char* file);
        void saveToFile(const char* file);
        //Commands
        bool enroll( int fn, const char* program, int group, const char* name );
        void print( int fn );
        void printall( const char* program, int year );
        void protocol( const char* course );
        void report( int fn );
        bool open( const char* file );
        void close();
        bool save();
        bool saveAs( const char* file );
        void help();
    public:
        Susi();
        ~Susi();
        bool update();

};

#endif //__SUSI_HPP