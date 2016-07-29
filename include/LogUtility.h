#ifndef LOGUTILITY_INCLUDE
#define LOGUTILITY_INCLUDE
#include	<log4cpp/BasicLayout.hh>
#include	<log4cpp/Category.hh>
#include	<log4cpp/FileAppender.hh>
#include <boost/noncopyable.hpp>
#include <memory>
#include <string>
#include <pthread.h>
class Logger final:public boost::noncopyable{
private:
     log4cpp::Category* category;
     std::string& MessageWrapper(std::string& message,const char* ,int);
     void InitLogger(log4cpp::Appender* appender);
     void AddLogger(log4cpp::Appender* appender);
public:
    Logger();
    ~Logger();
     void Start();
     void Error( std::string& errorMessage,const char* fileName,int lineNumber);
     void Error( const char* errorMessage,const char*  fileName,int lineNumber);
     void Warn(const char* warnMessage,const char*  fileName,int lineNumber);
     void Warn( std::string& warnMessage,const char*  fileName,int lineNumber);
     void Debug( std::string& warnMessage,const char*  fileName,int lineNumber);
     void Debug( const char* warnMessage,const char*  fileName,int lineNumber);
     void ShutDown();
};
class LogUtility final:public boost::noncopyable
{
private:
    LogUtility();
public:
    static Logger& GetInstance();
};

#endif