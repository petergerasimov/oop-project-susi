#include "susi.hpp"

Susi::Susi()
{

}
Susi::~Susi()
{

}
bool Susi::update()
{
    std::cout << "Enter command:\n$ ";
    std::cin >> c;
    bool worked = true;
    if( !strcmp( c.arg(0), "enroll" ) )
    {
        enroll( atoi( c.arg(1) ), c.arg(2), atoi( c.arg(3) ), c.arg(4) );
    }
    else if( !strcmp( c.arg(0), "advance" ) )
    {
        worked = getStudent( atoi(c.arg(1)) )->advance();
    }
    else if( !strcmp( c.arg(0), "change" ) )
    {
        worked = getStudent( atoi(c.arg(1)) )->change( c.arg(2), c.arg(3) );
    }
    else if( !strcmp( c.arg(0), "graduate" ) )
    {
        worked = getStudent( atoi(c.arg(1)) )->graduate();
    }
    else if( !strcmp( c.arg(0), "graduate" ) )
    {
        worked = getStudent( atoi(c.arg(1)) )->graduate();
    }
    else if( !strcmp( c.arg(0), "interrupt" ) )
    {
        getStudent( atoi(c.arg(1)) )->interrupt();
    }
    else if( !strcmp( c.arg(0), "resume" ) )
    {
        getStudent( atoi(c.arg(1)) )->resume();
    }
    else if( !strcmp( c.arg(0), "print" ) )
    {
        print( atoi( c.arg(1) ) );
    }
    else if( !strcmp( c.arg(0), "exit" ) )
    {
        return false;
    }

    if( worked )
    {
        std::cout << "Success!" << std::endl;
    }
    else
    {
        std::cout << "Something went wrong :(" << std::endl;
    }
    

    return true;
}
Student* Susi::getStudent( int fn )
{
    for( auto& student : students )
    {
        if( student.getFN() == fn )
        {
            return &student;
        }
    }
    return nullptr;
}
void Susi::loadFromFile( const char* file )
{

}
void Susi::saveToFile( const char* file )
{

}
//Commands
void Susi::enroll( int fn, const char* program, int group, const char* name )
{
    Student temp( name, fn, group, program );
    students.push_back( temp );
}
void Susi::print( int fn )
{
    if( !getStudent( fn ) )
        return;
    std::cout << getStudent( fn )->getName() << ' '
              << getStudent( fn )->getFN() << ' '
              << getStudent( fn )->getProgram() << ' '
              << getStudent( fn )->gradeAverage() << '\n';
}
void Susi::printall( const char* program, int year )
{
    for( auto& student : students )
    {
        if( student.getProgram() == std::string(program) && 
            student.getYear() == year )
        {
            std::cout << student.getName() << ' '
                      << student.getFN() << ' '
                      << student.getProgram() << ' '
                      << student.gradeAverage() << '\n';
        }
    }
}
void Susi::protocol( char* course )
{
    for( auto& student : students )
    {
        if( student.isInCourse( course ) )
        {
            std::cout << student.getName() << ' '
                      << student.getFN() << ' '
                      << student.gradeAverage() << '\n';
        }
    }
}
void Susi::report( int fn )
{
    // TODO: Add more info
    print( fn );
}
bool Susi::open( const char* file )
{
    if( file )
    {
        currentFile = file;
    }
    if( !currentFile.empty() )
    {
        loadFromFile( currentFile.c_str() );
        return true;
    }
    return false;
}
void Susi::close()
{
    currentFile.clear();
}
bool Susi::save()
{
    saveAs( currentFile.c_str() );
}
bool Susi::saveAs( const char* file )
{
    saveToFile( file );
}
void Susi::help()
{
    std::cout << "exit - exits program" << std::endl;
}