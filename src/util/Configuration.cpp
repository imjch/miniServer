#include "Configuration.h"
#include "rapidjson/document.h"
#include "rapidjson/reader.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>
#include <ServerDefine.h>
#include <unordered_map>
#include "Exception.h"
rapidjson::Document Configuration::document;
Configuration::_constructor Configuration::_con;

 std::string Configuration::GetAttribute(const char* attr){

     if(!document.HasMember(attr)){
         std::string errMsg("configuration field not found");
         LogError(errMsg);
         throw NoDataFoundException(errMsg);
     }
     auto val = document.FindMember(attr);
    return std::string(val->value.GetString());
}

std::string Configuration::LogFileName(){
    return GetAttribute("logfile");
}
//std::string Configuration::ServerType(){
//    return GetAttribute("type");
//}

ServerRole Configuration::ServerType(){
    std::unordered_map<std::string,ServerRole> map{{"files",ServerRole::FILES},{"http",ServerRole::HTTP}};
    if(map.count(GetAttribute("type"))<=0){
        LogError("invalid server type");
        throw ServerException("invalid server type");
    }
    return map[GetAttribute("type")];
}