#include "command.hpp"

void Command::extractArgs()
{
    char* currentArg = std::strtok( cmd, " " );
    while ( currentArg != nullptr )
    {
        args.push_back( currentArg );
        currentArg = std::strtok( nullptr, " " );
    }
}
std::istream &operator>>( std::istream  &in, Command &c )
{
    c.args.clear();
    in.getline( c.cmd, c.MAX_CMD );
    c.extractArgs();
    return in;
}
const char* Command::arg( unsigned pos )
{
    if( pos < numberOfArgs() )
    {
        return args[pos].c_str();
    }
    return nullptr;
}
int Command::numberOfArgs()
{
    return args.size();
}
