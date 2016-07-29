#include "LogUtility.h"
#include  <log4cpp/BasicLayout.hh>
#include  <log4cpp/Category.hh>
#include  <log4cpp/FileAppender.hh>
#include <log4cpp/OstreamAppender.hh>
#include <ctime>
#include <string>
#include <Configuration.h>

Logger::Logger():category(nullptr){
    Start();
}
Logger::~Logger(){
    category->~Category();
}
 void Logger::Start(){
    std::string logFileName(Configuration::LogFileName());
    std::remove(logFileName.c_str());
    auto osAppender=new log4cpp::OstreamAppender("MiniServerAppender",&std::cout);
    auto fileAppender=new log4cpp::FileAppender("MiniServerAppender",logFileName);
    fileAppender->setLayout(new log4cpp::BasicLayout());
    osAppender->setLayout(new log4cpp::BasicLayout());
    Logger::InitLogger(fileAppender);
    Logger::AddLogger(osAppender);
}

 std::string&  Logger::MessageWrapper(std::string& message,const char*  fileName ,int lineNumber){
    char timeStr[64];
    time_t t=time(NULL);
    strftime(timeStr,64,"\t%Y-%m-%d %X\t",localtime(&t));
    return message.append(timeStr).append("\tfile:\t").append(fileName).append("\tline:\t").append(std::to_string(lineNumber));
}

 void Logger::InitLogger( log4cpp::Appender* appender)
{
     category=&log4cpp::Category::getRoot();
     category->setAdditivity(true);
     category->setAppender(appender);
     category->setPriority(log4cpp::Priority::DEBUG);
}

 void Logger::AddLogger(log4cpp::Appender* appender){
     category->setAppender(appender);
}
 void  Logger::Error( std::string& errorMessage,const char*  fileName,int lineNumber){
     category->error(MessageWrapper(errorMessage,fileName,lineNumber));
 }
void  Logger::Error( const char* errorMessage,const char*  fileName,int lineNumber){
    auto message=std::string(errorMessage);
    Error(message,fileName,lineNumber);
}
void Logger::Warn(const char* warnMessage,const char*  fileName,int lineNumber){
    auto message=std::string(warnMessage);
    Warn(message,fileName,lineNumber);
}
 void Logger::Warn( std::string& warnMessage,const char*  fileName,int lineNumber){
    category->warn(MessageWrapper(warnMessage,fileName,lineNumber));
}

 void Logger::ShutDown(){
     category->shutdown();
 }

void Logger::Debug(std::string& infoMessage,const char*  fileName,int lineNumber){
    category->debug(MessageWrapper(infoMessage,fileName,lineNumber));
}

void Logger::Debug(const char* infoMessage,const char*  fileName,int lineNumber){
    auto message=std::string(infoMessage);
    Debug(message,fileName,lineNumber);
}


Logger& LogUtility::GetInstance(){
    static Logger logger;
    return logger;
}
