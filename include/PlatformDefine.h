#ifndef PLATFORMDEFINE_INCLUDE
#define PLATFORMDEFINE_INCLUDE
#include <stdexcept>

enum PlatformType{
    Java,
    PHP
};

PlatformType GetPlatformTypeByExtName(const std::string& extName);

#endif