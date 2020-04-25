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
        worked = enroll( atoi( c.arg(1) ), c.arg(2), atoi( c.arg(3) ), c.arg(4) );
    }
    else if( !strcmp( c.arg(0), "advance" ) )
    {
        if(getStudent( atoi(c.arg(1))) )
        {
            worked = getStudent( atoi(c.arg(1)) )->advance();
        }
        else
        {
            worked = false;
        }
    }
    else if( !strcmp( c.arg(0), "change" ) )
    {
        if(getStudent( atoi(c.arg(1))) )
        {
            worked = getStudent( atoi(c.arg(1)) )->change( c.arg(2), c.arg(3) );
        }
        else
        {
            worked = false;
        }
    }
    else if( !strcmp( c.arg(0), "graduate" ) )
    {
        if(getStudent( atoi(c.arg(1))) )
        {
            worked = getStudent( atoi(c.arg(1)) )->graduate();
        }
        else
        {
            worked = false;
        }
    }
    else if( !strcmp( c.arg(0), "interrupt" ) )
    {
        if(getStudent( atoi(c.arg(1))) )
        {
            getStudent( atoi(c.arg(1)) )->interrupt();
        }
        else
        {
            worked = false;
        }
    }
    else if( !strcmp( c.arg(0), "resume" ) )
    {
        if(getStudent( atoi(c.arg(1))) )
        {
            getStudent( atoi(c.arg(1)) )->resume();
        }
        else
        {
            worked = false;
        }

    }
    else if( !strcmp( c.arg(0), "print" ) )
    {
        print( atoi( c.arg(1) ) );
    }
    else if( !strcmp( c.arg(0), "printall" ) )
    {
        printall( c.arg(1), atoi( c.arg(2) ) );
    }
    else if( !strcmp( c.arg(0), "enrollin" ) )
    {
        if(getStudent( atoi(c.arg(1))) )
        {
            getStudent( atoi(c.arg(1)) )->enrollin( c.arg(2) );
        }
        else
        {
            worked = false;
        }
    }
    else if( !strcmp( c.arg(0), "addgrade" ) )
    {
        if(getStudent( atoi(c.arg(1))) )
        {
            getStudent( atoi(c.arg(1)) )->addGrade( c.arg(2), atoi( c.arg(3) ) );
        }
        else
        {
            worked = false;
        }
    }
    else if( !strcmp( c.arg(0), "protocol" ) )
    {
        protocol( c.arg(1) );
    }
    else if( !strcmp( c.arg(0), "report" ) )
    {
        report( atoi( c.arg(1) ) );
    }
    else if( !strcmp( c.arg(0), "help" ) )
    {
        help();
    }
    else if( !strcmp( c.arg(0), "exit" ) )
    {
        return false;
    }
    else
    {
        std::cout << "Unknown command\n" << std::endl;
        worked = false;
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
bool Susi::enroll( int fn, const char* program, int group, const char* name )
{
    if( !fn || !program || !group || !name )
        return false;
    Student temp( name, fn, group, program );
    students.push_back( temp );
    return true;
}
void Susi::print( int fn )
{
    if( !getStudent( fn ) )
        return;
    std::cout << getStudent( fn )->getName() << ' '
              << getStudent( fn )->getFN() << ' '
              << getStudent( fn )->getProgram() << ' '
              << getStudent( fn )->getYear() << ' '
              << getStudent( fn )->gradeAverage() << '\n';
}
void Susi::printall( const char* program, int year )
{
    if( !program )
        return;

    for( auto& student : students )
    {
        if( !student.getProgram().compare(program) && 
            student.getYear() == year )
        {
            std::cout << student.getName() << ' '
                      << student.getFN() << ' '
                      << student.getProgram() << ' '
                      << student.getYear() << ' '
                      << student.gradeAverage() << '\n';
        }
    }
}
void Susi::protocol( const char* course )
{
    if( !course )
        return;
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
    return saveAs( currentFile.c_str() );
}
bool Susi::saveAs( const char* file )
{
    saveToFile( file );
    return true;
}
void Susi::help()
{
    std::cout << "exit - exits program" << std::endl;
}