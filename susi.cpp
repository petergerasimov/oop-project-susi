#include <fstream>

#include "susi.hpp"

Susi::Susi()
{
    currentFile = "default.dat";
    open( currentFile.c_str() );
    isFileOpen = true;
}
Susi::~Susi()
{
    currentFile.clear();
    students.clear();
}
bool Susi::update()
{
    std::cout << "Enter command:\n$ ";
    std::cin >> c;
    bool worked = true;
    if ( c.numberOfArgs() <= 0 )
    {
        std::cout << "Please enter a command!" << std::endl;
        return true;
    }
    if ( isFileOpen )
    {
        if ( !strcmp(c.arg(0), "enroll") )
        {
            worked = enroll(atoi(c.arg(1)), c.arg(2), atoi(c.arg(3)), c.arg(4));
        }
        else if ( !strcmp(c.arg(0), "advance") )
        {
            if ( getStudent(atoi(c.arg(1))) )
            {
                worked = getStudent( atoi(c.arg(1)) )->advance();
            }
            else
            {
                worked = false;
            }
        }
        else if ( !strcmp( c.arg(0), "change" ) )
        {
            if ( getStudent( atoi(c.arg(1)) ) )
            {
                worked = getStudent( atoi( c.arg(1) ) )->change( c.arg(2), c.arg(3) );
            }
            else
            {
                worked = false;
            }
        }
        else if (!strcmp( c.arg(0), "graduate" ))
        {
            if (getStudent(atoi(c.arg(1))))
            {
                worked = getStudent( atoi( c.arg(1) ) )->graduate();
            }
            else
            {
                worked = false;
            }
        }
        else if (!strcmp( c.arg(0), "interrupt" ))
        {
            if ( getStudent( atoi( c.arg(1) ) ) )
            {
                getStudent( atoi( c.arg(1) ) )->interrupt();
            }
            else
            {
                worked = false;
            }
        }
        else if ( !strcmp( c.arg(0), "resume" ) )
        {
            if (getStudent(atoi(c.arg(1))))
            {
                getStudent(atoi(c.arg(1)))->resume();
            }
            else
            {
                worked = false;
            }
        }
        else if ( !strcmp( c.arg(0), "print" ) )
        {
            print( atoi(c.arg(1)) );
        }
        else if ( !strcmp( c.arg(0), "printall" ) )
        {
            printall( c.arg(1), atoi(c.arg(2)) );
        }
        else if ( !strcmp( c.arg(0), "enrollin" ) )
        {
            if (getStudent(atoi(c.arg(1))))
            {
                worked = getStudent( atoi( c.arg(1) ))->enrollin(c.arg(2) );
            }
            else
            {
                worked = false;
            }
        }
        else if ( !strcmp( c.arg(0), "addgrade" ) )
        {
            if ( getStudent( atoi( c.arg(1) ) ) )
            {
                worked = getStudent( atoi( c.arg(1) ) )->addGrade( c.arg(2), atof(c.arg(3) ) );
            }
            else
            {
                worked = false;
            }
        }
        else if ( !strcmp( c.arg(0), "protocol" ) )
        {
            protocol( c.arg(1) );
        }
        else if ( !strcmp( c.arg(0), "report" ) )
        {
            report( atoi( c.arg(1) ) );
        }
        else if ( !strcmp( c.arg(0), "close" ) )
        {
            close();
        }
        else if ( !strcmp( c.arg(0), "save" ) )
        {
            save();
        }
        else if ( !strcmp( c.arg(0), "saveas" ) )
        {
            saveAs( c.arg(1) );
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
    }
    else
    {
        std::cout << "Please open a file!\n";
        if( !strcmp( c.arg(0), "help" ) )
        {
            help();
        }
        else if( !strcmp( c.arg(0), "exit" ) )
        {
            return false;
        }
        else if( !strcmp( c.arg(0), "open" ) )
        {
            open( c.arg(1) );
        }
        else
        {
            std::cout << "Unknown command\n" << std::endl;
            worked = false;
        }
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
    std::ifstream infile;
    infile.open( file , std::ios::binary | std::ios::in );
    if( infile )
    {
        // numOfStudents [int]
        // students [vector]
        int numOfStudents = 0;
        infile.read( ( char * ) &numOfStudents, sizeof( numOfStudents ) );
        for( int i = 0; i < numOfStudents && !infile.eof() ; i++ )
        {
            // nameLen [int]
            // name [string]
            // ------------
            // fn [int]
            // year [int]
            // group [int]
            // status [int]
            // programLen [int]
            // -------------
            // program [string]
            // numOfCourses [int]
            // courses [vector]
            Student tempStudent;
            int nameLen = 0;
            infile.read( ( char * ) &nameLen, sizeof( nameLen ) );
            
            std::string name;
            for( int j = 0; j < nameLen && !infile.eof() ; j++ )
            {
                char c;
                infile.read( &c, sizeof( c ) );
                name.push_back( c );
            }
            tempStudent.setName( name );
            
            const int CONS_INTS = 5;
            int sAttributes[CONS_INTS] = {0,};
            infile.read( ( char * ) &sAttributes, sizeof(int) * CONS_INTS);

            tempStudent.setFN( sAttributes[0] );
            tempStudent.setYear( sAttributes[1] );
            tempStudent.setGroup( sAttributes[2] );
            tempStudent.setStatus( sAttributes[3] );
            
            std::string program;
            for( int j = 0; j < sAttributes[4] && !infile.eof() ; j++ )
            {
                char c;
                infile.read( &c, sizeof( c ) );
                program.push_back( c );
            }
            tempStudent.setProgram( program );

            int numOfCourses = 0;
            infile.read( ( char * ) &numOfCourses, sizeof( numOfCourses ) );
            for( int j = 0; j < numOfCourses; j++ )
            {
                // courseNameLen [int]
                // courseName [string]
                // grade [float]
                // mandatory [bool]
                Course course;
                int courseNameLen = 0;
                course.name.clear();
                infile.read( ( char * ) &courseNameLen, sizeof( courseNameLen ) );
                for( int k = 0; k < courseNameLen && !infile.eof() ; k++ )
                {
                    char c;
                    infile.read( &c, sizeof( c ) );
                    course.name.push_back( c );
                }
                infile.read( ( char * ) &course.grade, sizeof( course.grade ) );
                infile.read( ( char * ) &course.mandatory, sizeof( course.mandatory ) );

                tempStudent.addCourse(course);
            }
            students.push_back(tempStudent);
        }
    }
    infile.close();
}
void Susi::saveToFile( const char* file )
{
    if( !students.empty() )
    {
        // numOfStudents [int]
        // students [vector]
        std::ofstream outfile;
        outfile.open( file, std::ios::binary | std::ios::out | std::ios::trunc);

        int numOfStudents = students.size();
        outfile.write( (char *)&numOfStudents, sizeof( numOfStudents ) );
        for( int i = 0; i < numOfStudents; i++ )
        {
            // nameLen [int]
            // name [string]
            // ---------------
            // fn [int]
            // year [int]
            // group [int]
            // status [int]
            // programLen [int]
            // ---------------
            // program [string]
            // numOfCourses [int]
            // courses [vector]
            int nameLen = students[i].getName().length();
            outfile.write( (char *)&nameLen, sizeof( nameLen ) );
            outfile.write( students[i].getName().c_str(), sizeof( char ) * nameLen );

            int fn = students[i].getFN();
            outfile.write( (char *)&fn, sizeof( fn ) );
            int year = students[i].getYear();
            outfile.write( (char *)&year, sizeof( year ) );
            int group = students[i].getGroup();
            outfile.write( (char *)&group, sizeof( group ) );
            int status = students[i].getStatus();
            outfile.write( (char *)&status, sizeof( status ) );

            int programLen = students[i].getProgram().length();
            outfile.write( (char *)&programLen, sizeof( programLen ) );
            outfile.write( students[i].getProgram().c_str(), sizeof( char ) * programLen );

            int numOfCourses = students[i].numberOfCourses();
            outfile.write( (char *)&numOfCourses, sizeof( numOfCourses ) );
            for( int j = 0; j < numOfCourses; j++ )
            {
                // courseNameLen [int]
                // courseName [string]
                // grade [float]
                // mandatory [bool]
                int courseNameLen = students[i].getCourses()[j].name.size();
                outfile.write( (char *)&courseNameLen, sizeof( courseNameLen ) );
                outfile.write( students[i].getCourses()[j].name.c_str(), sizeof( char ) * courseNameLen );

                float grade = students[i].getCourses()[j].grade;
                outfile.write( (char *)&grade, sizeof( grade ) );

                bool mandatory = students[i].getCourses()[j].mandatory;
                outfile.write( (char *)&mandatory, sizeof( mandatory ) );
            }
        }
        outfile.close();
    }
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
    std::cout << *getStudent( fn ) << std::endl;
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
            std::cout << student << std::endl;
        }
    }
}
void Susi::protocol( const char* course )
{
    if( !course )
        return;

    std::vector<Student*> toSort;
    for( auto& student : students )
    {
        if( student.isInCourse( course ) )
        {
            toSort.push_back(&student);
        }
    }
    if(toSort.size() > 0)
    {
        sortStudents(toSort);
        for( auto& student : toSort )
        {
            std::cout << (*student) << std::endl;
        }
    }
    
}
void Susi::report( int fn )
{
    if( !getStudent( fn ) )
        return;
    std::cout << *getStudent( fn ) << std::endl;
    for( const auto& course : getStudent( fn )->getCourses() )
    {
        std::cout << course.name << ' ' << course.grade << std::endl;
    }
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
        isFileOpen = true;
        return true;
    }
    return false;
}
void Susi::close()
{
    currentFile.clear();
    students.clear();
    isFileOpen = false;
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

void Susi::sortStudents( std::vector<Student *> &toSort )
{
    for (int i = 0; i < toSort.size() - 1; i++)
    {
        for (int j = i + 1; j > 0; j--)
        {
            if (toSort[j - 1]->getFN() > toSort[j]->getFN())
            {
                Student* temp = toSort[j - 1];
                toSort[j - 1] = toSort[j];
                toSort[j] = temp;
            }
            else
            {
                break;
            }
        }
    }
}