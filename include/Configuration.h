#ifndef CONFIGURATION_H
#define CONFIGURATION_H
#include <fstream>
#include <unistd.h>
#include <string>
#include <boost/noncopyable.hpp>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <ServerDefine.h>
#include <Exception.h>
class Configuration final:public boost::noncopyable{
private:

    struct _constructor{
        _constructor(){

            try {
                char location[1024];
                getcwd(location,1024);
                std::ifstream infile("/home/jc/Code/miniServer/build/bin/config");
                std::string content;
                std::string str;

                if(!infile.good()){
                    std::string errMsg("file not found");
                    LogError(errMsg);
                    throw ::NoFileFoundException(errMsg);
                }
                if (infile.is_open())
                {
                    while(!infile.eof()) // To get you all the lines.
                    {
                        getline(infile,str); // Saves the line in STRING.
                        content.append(str);
                    }
                    infile.close();

                    document.Parse(content.c_str());
                }
            }
            catch(std::exception& e){
                std::cout<<e.what()<<std::endl;
            }
        }
    };
    static _constructor _con;
    static rapidjson::Document document;
    static  std::string GetAttribute(const char* attr);

public:
    static  std::string LogFileName();

    static  ServerRole ServerType();
};

#endif