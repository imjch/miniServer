#ifndef FILESERVER_H
#define FILESERVER_H
#include "RoleServer.h"
#include "ServerDefine.h"
class FileServer:public IRoleServer{
private:
    void HandleRequest(FileDescripterType connfd);

public:
    FileServer();
    void Start() override;
    std::string GetServerName() override;
};

#endif