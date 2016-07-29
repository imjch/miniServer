#ifndef HTTPSERVER_INCLUDE
#define HTTPSERVER_INCLUDE
#include "HTTPMessageHandler.h"
#include <string>
#include "RoleServer.h"
#include "ServerDefine.h"

class HTTPServer:public IRoleServer
{
public:
    HTTPServer();
    void Start() override;
    std::string GetServerName();
private:
    HTTPMessage http_message;
    void HandleRequest(FileDescripterType connfd);
    void HandleHTTP(HTTPMessage& httpMessage);
};


#endif