#ifndef ROLESERVER_H
#define ROLESERVER_H
#include "ServerDefine.h"
#include <memory>

class IRoleServer{
public:
    virtual void Start()=0;
    virtual std::string GetServerName()=0;
     IRoleServer()=default;
     virtual ~IRoleServer()=default;
};

typedef std::shared_ptr<IRoleServer> RoleServer;
RoleServer ConstructServer();
#endif
