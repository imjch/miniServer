#ifndef NETUTILITY_INCLUDE
#define NETUTILITY_INCLUDE
#include "ServerDefine.h"
#include <string>
class NetUtility
{
public:
    static std::string GetIPAddressByName( const std::string& hostName);
    static std::string ReadAll(FileDescripterType fd);
    static std::string ReadAll(FILE* fd);
    static std::shared_ptr<char> ReadData(FileDescripterType fd,size_t size);
    static std::shared_ptr<char>  ReadData(FILE* fd,size_t size);

    static void Write(FileDescripterType fd,const std::string& str);
    static void Write(FILE* fd,const std::string& str);
    static void WriteData(FILE* fd,void* buf);
    static void WriteData(FileDescripterType fd,void* buf);
};

#endif