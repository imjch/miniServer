#include "HTTPServer.h"
#include "HTTPMessageHandler.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unp.h>
#include "LogUtility.h"
#include <error.h>
#include <ServerException.h>
#include "NetUtility.h"
#include "HTTPExecutor.h"

HTTPServer::HTTPServer() {

}

void HTTPServer::HandleHTTP(HTTPMessage& httpMessage){
    HTTPExecutor executor(httpMessage);
   // executor.ProcessHeaderLocation();
}

std::string HTTPServer::GetServerName(){
    return "HTTPServer";
}

void HTTPServer::HandleRequest(FileDescripterType connfd){
    HTTPMessageHandler messageHandler;
    try{
        HTTPMessage httpMessage = messageHandler.ConstructHTTPMessage(NetUtility::ReadAll(connfd));
        this->HandleHTTP(httpMessage);
        ::close(connfd);
    }
    catch(NetReadDataException ex){
        LogError(ex.what());
    }
    catch(std::runtime_error ex){
        LogError(ex.what());
        std::abort();
    }
}

void HTTPServer::Start() {
    LogDebug("server start initiation...");
    FileDescripterType listenfd = ::socket(AF_INET,SOCK_STREAM,0);
    if(listenfd < 0){
        LogError(strerror(errno));
        std::abort();
    }

    sockaddr_in sockAddr,cliAddr;
    ::bzero(&sockAddr ,0);



    sockAddr.sin_family=AF_INET;
    sockAddr.sin_port=htons(9877);//convert byte order.
    auto val = ::inet_pton(AF_INET,"127.0.0.1",&sockAddr.sin_addr);
    if(val<=0){
        LogError(::strerror(errno));
        std::abort();
    }

    if(::bind(listenfd,(sockaddr*)&sockAddr,sizeof(sockAddr))<0)
    {
        LogError(::strerror(errno));
        std::abort();
    }

    if(::listen(listenfd,LISTENQ)<0){
        LogError(::strerror(errno));
        std::abort();
    }



    LogDebug("server initiation success...");
    LogDebug("server start listening...");
    for(;;){
        LogDebug("main process start accepting...");
        FileDescripterType connFD;
        socklen_t cliSize=sizeof(cliAddr);
        connFD=::accept(listenfd,(SA*)&cliAddr,&cliSize);
        LogDebug("main process acception done...");
        if(connFD<0){
            LogError(strerror(errno));
            std::abort();
        }

        FileDescripterType childFD;
        if((childFD=fork())==0){
            LogDebug("child process start processing...");
            ::close(listenfd);//child process must close the socket descripter.
            this->HandleRequest(connFD);
            LogDebug("child process handled request...");
            std::abort();
        }
        ::close(connFD);
    }
}