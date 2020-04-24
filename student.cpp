#include "student.hpp"
#include <cstring>

Student::Student()
{
    setName( "None" );
    setFN( 0 );
    setGroup( 0 );
    setProgram( "None" );
    setStatus( 0 );
    setYear( 0 );
}
Student::Student( std::string name, int fn, 
         int group, std::string program )
{
    enroll( name, fn, group, program );
}
Student::~Student()
{
    name.clear();
    program.clear();
    courses.clear();
}
//Setters
void Student::setName( std::string name )
{
    this->name = name;
}
void Student::setFN( int fn )
{
    this->fn = fn;
}
void Student::setGroup( int group )
{
    this->group = group;
}
void Student::setStatus( int status )
{   
    this->status = status;
}
void Student::setProgram( std::string program )
{
    this->program = program;
}
void Student::setYear( int year )
{
    this->year = year;
}
//Getters
const std::string Student::getName() const
{
    return this->name;
}
const int Student::getFN() const
{
    return this->fn;
}
const int Student::getGroup() const
{
    return this->group;
}
const int Student::getStatus() const
{
    return this->status;
}
const std::string Student::getProgram() const
{
    return this->program;
}
const int Student::getYear() const
{
    return this->year;
}
//
void Student::enroll( std::string name, int fn, 
                      int group, std::string program )
{
    setName( name );
    setFN( fn );
    setGroup( group );
    setProgram( program );
    setStatus( 0 );
    setYear( 1 );
}
bool Student::advance()
{
    if( gradeAverage() > MIN_PASS_GRADE )
    {
        this->year++;
        return true;
    }
    return false;
}
bool Student::change( char* option, char* value )
{
    static const int MIN_PASSED_COURSES = 2;
    if(!strcmp( option, "program" ))
    {
        // TODO:
        // Прехвърлянето в друга специалност е възможно само,
        // ако студентът е положил успешно изпити по всички 
        // задължителни предмети от минали курсове на новата специалност.
        setProgram(std::string(value));
        return true;

    }
    else if(!strcmp( option, "group" ))
    {
        setGroup( atoi(value) );
        return true;
    }
    else if(!strcmp( option, "year" ))
    {
        if( unpassedCount() <= MIN_PASSED_COURSES )
        {
            if( this->year + 1 == atoi( value ) )
            {
                this->year++;
                return true;
            }
        }
    }
    return false;
}
bool Student::graduate()
{
    if( unpassedCount( false ) == 0 )
    {
        this->status = graduated;
        return true;
    }
    return false;
}
void Student::interrupt()
{
    this->status = interrupted;
}
void Student::resume()
{
    this->status = active;
}
bool Student::enrollin( char* course )
{


}
bool Student::addGrade( char* course, float grade )
{

}
float Student::gradeAverage()
{
    if( !courses.size() )
        return 0;

    float sum = 0;
    for( auto& course : courses )
    {
        sum += course.grade;
    }
    return sum / courses.size();
}

int Student::unpassedCount( bool mandatory )
{
    int count = 0;
    for( auto& course : courses )
    {
        if( mandatory )
        { 
            if( course.grade < MIN_PASS_GRADE && course.mandatory )
            {
                count++;
            }
        }
        else
        {
            if( course.grade < MIN_PASS_GRADE )
            {
                count++;
            }
        }
    }
    return count;
}