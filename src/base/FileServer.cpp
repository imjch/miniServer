#include <LogUtility.h>
#include <sys/socket.h>
#include <cstring>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "string_utility.h"
#include <Exception.h>
#include "FileServer.h"
#include "NetUtility.h"
#include <fstream>

FileServer::FileServer(){

}
std::string FileServer::GetServerName(){
    return "FileServer";
}
void FileServer::HandleRequest(FileDescripterType connfd) {
    try {
        std::string fileNameAndLengh= NetUtility::ReadAll(connfd);
        std::vector<std::string> v;
//        string_utility::split(fileNameAndLengh,',',v);
//        string_utility::trim(std::string("asdasd"));
//        if(v[0].size()<=0){
//            std::string errMsg("internal error: no filename parammeter ");
//            LogError(errMsg);
//            throw ::InvalidParameterException(errMsg);
//        }
//        if(std::atoi(v[1].c_str())<0){
//            std::string errMsg("internal error: file size error ");
//            LogError(errMsg);
//            throw ::InvalidParameterException(errMsg);
//        }
        assert(v[0].size()>0);
        assert(std::atoi(v[1].c_str())>=0);

        auto fileName=v[0];
        auto fileSize=v[1];

        LogWarn(std::string("Got file name :").append(fileName));
        LogWarn(std::string("Got file size :").append(fileSize));
       // LogWarn(std::string("the length of this file is :").append());
        LogWarn("Ready to receive files...");
       // std::string fileContent=NetUtility::ReadAll(connfd);
    }
    catch(NetReadDataException& e){
        std::string str("GET CONTENT ERROR : ");
        LogError(str.append(e.what()));
        NetUtility::Write(connfd,"0");// 0 indicate that a error occured
        std::abort();
    }

}
void FileServer::Start() {
    LogWarn("file server is starting...");
    FileDescripterType listenfd;
    listenfd=::socket(AF_INET,SOCK_STREAM,0);
    if(listenfd<0){
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
        connFD=::accept(listenfd,(sockaddr*)&cliAddr,&cliSize);
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
            ::exit(EXIT_SUCCESS);
        }
        ::close(connFD);
    }
}
