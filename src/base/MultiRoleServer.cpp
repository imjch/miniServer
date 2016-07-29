#include <HTTPServer.h>
#include <LogUtility.h>
#include "MultiRoleServer.h"
#include "FileServer.h"
//IRoleServer::RoleServer RleServer(ServerRole role){
//    switch(role){
//        case ServerRole::FILES:
//            return IRoleServer::RoleServer(new FileServer());
//        case ServerRole ::HTTP:
//            return IRoleServer::RoleServer(new HTTPServer());
//        default:
//            LogDebug("invalid role");
//            throw std::runtime_error("invalid role");
//    }
//}
//
//MultiRoleServer::~MultiRoleServer(){
//
//}
//MultiRoleServer::MultiRoleServer(IRoleServer::RoleServer role):server(role){
//
//}
//
//void MultiRoleServer::Start(){
//    server->Start();
//}
//ServerRole MultiRoleServer::Role(){
//    return server->Role();
//}