#ifndef EXCEPTION_INCLUDE
#define EXCEPTION_INCLUDE
#include <stdexcept>
class PlatformNotSupportedException:public std::runtime_error{
public:
    explicit PlatformNotSupportedException(const std::string& errorMessage):std::runtime_error(errorMessage){}
    explicit PlatformNotSupportedException(const char* errorMessage):std::runtime_error(errorMessage){}
};

class NotImplementedException:public std::runtime_error{
public:
    explicit NotImplementedException(const std::string& errorMessage):std::runtime_error(errorMessage){}
    explicit NotImplementedException(const char* errorMessage):std::runtime_error(errorMessage){}
};

class NetReadDataException:public std::runtime_error{
public:
    explicit NetReadDataException(const std::string& message):std::runtime_error(message){}
    explicit NetReadDataException(const char* message):std::runtime_error(message){}
};
class NetWriteDataException:public std::runtime_error{
public:
    explicit NetWriteDataException(const std::string& message):std::runtime_error(message){}
    explicit NetWriteDataException(const char* message):std::runtime_error(message){}
};
class NoDataFoundException:public std::runtime_error{
public:
    explicit NoDataFoundException(const std::string& message):std::runtime_error(message){}
    explicit NoDataFoundException(const char* message):std::runtime_error(message){}
};

class NoFileFoundException:public std::runtime_error{
public:
    explicit NoFileFoundException(const std::string& message):std::runtime_error(message){}
    explicit NoFileFoundException(const char* message):std::runtime_error(message){}
};
class InvalidParameterException:public std::runtime_error{
public:
    explicit InvalidParameterException(const std::string& message):std::runtime_error(message){}
    explicit InvalidParameterException(const char* message):std::runtime_error(message){}
};

class ServerException:public std::runtime_error{
public:
    explicit ServerException(const std::string& message):std::runtime_error(message){}
    explicit ServerException(const char* message):std::runtime_error(message){}

};
#endif