#include <FileServer.h>
#include <HTTPServer.h>
#include <LogUtility.h>
#include <Configuration.h>
#include "RoleServer.h"


RoleServer ConstructServer(){
    auto serverType=Configuration::ServerType();
    switch(serverType){
        case ServerRole::FILES:
            return std::make_shared<FileServer>();
        case ServerRole::HTTP:
            return std::make_shared<HTTPServer>();
        default:
            LogDebug("invalid role");
            throw std::runtime_error("invalid role");
    }
}