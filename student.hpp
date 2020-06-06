#ifndef __STUDENT_HPP
#define __STUDENT_HPP

#include <string>
#include <vector>
#include <iostream>
#include "mytypes.hpp"

enum Status { interrupted = -1, active, graduated };

class Student
{
    private:
        static const int MIN_PASS_GRADE = 3;
        static const int MIN_PASSED_COURSES = 2;
        static const int GRADUATION_YEAR = 4;
        std::string name;
        int fn;
        int year;
        int group;
        int status;
        std::string program;
        std::vector< Course > courses;
        //Returns the number of courses that haven't been passed
        int unpassedCount( bool mandatory = true );
        //Get all the courses from the current year of the program the student is enrolled in
        const std::vector< Course >* getCoursesInYear() const;
    public:
        Student();
        Student( std::string name, int fn, 
                 int group, std::string program );
        ~Student();
        Student& operator=( const Student& s );
        friend std::ostream& operator<<(std::ostream &out, const Student &s);
        //Setters
        void setName( std::string name );
        void setFN( int fn );
        void setGroup( int group );
        void setStatus( int status );
        void setProgram( std::string program );
        void setYear( int year );
        //Getters
        const std::string getName() const;
        const int getFN() const;
        const int getGroup() const;
        const int getStatus() const;
        const std::string getProgram() const;
        const int getYear() const;
        const std::vector< Course > getCourses() const;
        //
        void enroll( std::string name, int fn, 
                     int group, std::string program );
        bool advance();
        bool change( const char* option, const char* value );
        bool graduate();
        void interrupt();
        void resume();
        bool enrollin( const char* course );
        bool addGrade( const char* course, float grade );
        const float gradeAverage() const;

        bool isInCourse( const char* course );
        int numberOfCourses();
};

#endif //__STUDENT_HPP