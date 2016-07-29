#include "NetUtility.h"
#include <string>
#include <unistd.h>
#include <netdb.h>
#include <stdexcept>
#include "LogUtility.h"
#include "ServerDefine.h"
#include "ServerException.h"
#include <stdio.h>
#include <cstring>
#include <iostream>
std::string NetUtility::GetIPAddressByName(const std::string &hostName) {
    //TODO:waiting for implementation
}

 void NetUtility::Write(FileDescripterType fd,const std::string& str){
//     ssize_t ret;
//     size_t len=str.size();
//     char* buf=new char[len];
//     memcpy(buf,str.c_str(),len);
//     while(len!=0&&(ret=write(fd,buf,len))){
//         if(ret==-1)
//         {
//             if(errno==EAGAIN){
//                 continue;
//             }
//             std::string errorMessage=std::string("Write error:").append(::strerror(errno));
//             LogError(errorMessage);
//             throw NetReadDataException(errorMessage);
//         }
//         len-=ret;
//         buf+=ret;
//     }
     auto fdStream=::fdopen(fd,"w");
     if(fdStream==NULL){
         std::string errorMessage=std::string("ReadAll error:").append(::strerror(errno));
         LogError(errorMessage);
         throw NetWriteDataException(errorMessage);
     }
     Write(fdStream,str);
}
 void NetUtility::Write(FILE* fdStream,const std::string& str){
    if((::fputs(str.c_str(),fdStream))==EOF){
        std::string errorMessage=std::string("ReadAll error:").append(::strerror(errno));
        throw NetWriteDataException(errorMessage);
    }
}

std::string NetUtility::ReadAll(FILE* fdStream) {
    char ptr[MAX_LINE];

    std::string str;

    while(!feof(fdStream)){
        ::fgets(ptr,MAX_LINE,fdStream);
        if(::ferror(fdStream)){
            std::string errorMessage=std::string("ReadAll error:").append(::strerror(errno));
            LogError(errorMessage);
            throw NetReadDataException(errorMessage);
        }
        str.append(ptr);

        memset(ptr,0,sizeof(ptr));
    }

    return str;
}

std::string NetUtility::ReadAll(FileDescripterType fd) {
    auto fdStream=::fdopen(fd,"r");
    if(fdStream==NULL){
        std::string errorMessage=std::string("ReadAll error:").append(::strerror(errno));
        LogError(errorMessage);
        throw NetReadDataException(errorMessage);
    }
    return ReadAll(fdStream);
}



//std::string NetUtility::ReadLine(FILE* fdStream) {
//    size_t leftCount;//count of data not received from client side
//    ssize_t readCount;//count of data received from client side
//    char ptr[MAX_LINE];
//    if(fgets(ptr,MAX_LINE,fdStream)==NULL){
//        std::string errorMessage=std::string("ReadLine error:").append(::strerror(errno));
//        LogError(errorMessage);
//        throw NetReadDataException(errorMessage);
//    }
//    return std::string(ptr);
//}

//std::string NetUtility::ReadLine(FileDescripterType fd) {
//    auto fdStream=::fdopen(fd,"r");
//    if(fdStream==NULL){
//        std::string errorMessage=std::string("ReadLine error:").append(::strerror(errno));
//        LogError(errorMessage);
//        throw NetReadDataException(errorMessage);
//    }
//    return ReadLine(fdStream);
//}

//std::string NetUtility::ReadRestrictedNumber(FileDescripterType fd,size_t n) {
//    size_t leftCount;//count of data not received from client side
//    int readCount;//count of data received from client side
//
//    char* ptr=new char[n];
//    char *head = ptr;
//    leftCount = n;
//    while (leftCount > 0) {
//        if ((readCount = ::read(fd, ptr, leftCount)) < 0) {
//            if (errno == EINTR) {
//                readCount = 0;
//            }
//            else {
//                std::string errorMessage=std::string(" ReadRestrictedNumber error:").append(::strerror(errno));
//                LogError(errorMessage);
//                throw NetReadDataException(errorMessage);
//            }
//        }
//        leftCount -= readCount;
//        ptr+=readCount;
//    }
//    LogDebug("child process received input...");
//    std::string str(head);
//    return str;
//}
//std::string NetUtility::ReadAll(FileDescripterType fd) {
////    size_t len=MAX_LINE;//count of data not received from client side
////    ssize_t ret;
////    char* buf=new char[MAX_LINE];
////    std::string str;
////    do{
////        //LogDebug("child process waits for reading...");
////        ret=::read(fd, buf, len);
////        LogDebug(std::to_string(ret).c_str());
////        //LogDebug("child process has finished reading...");
////        if (ret<0) {
////            if (errno == EINTR) {
////                continue;
////            }
////            else {
////                std::string errorMessage=std::string(" ReadAll error:").append(::strerror(errno));
////                LogError(errorMessage);
////                throw NetReadDataException(errorMessage);
////            }
////        }
////        if(ret==0){//0 indicate EOF
////            return str;
////        }
////        str.append(buf);
////    }
////    while(true);
//    return ReadAll(::fdopen(fd,"r"));
//}

//std::string NetUtility::ReadRestrictedNumber(FileDescripterType fd, size_t n) {
//   return ReadRestrictedNumber(::fdopen(fd,"r"),n);
//}
std::shared_ptr<char> NetUtility::ReadData(FileDescripterType fd,size_t size){
    auto fdStream=::fdopen(fd,"r");
    if(fdStream==NULL){
        std::string errorMessage=std::string("ReadData error:").append(::strerror(errno));
        LogError(errorMessage);
        throw NetReadDataException(errorMessage);
    }
    return ReadData(fdStream,size);
}
std::shared_ptr<char> NetUtility::ReadData(FILE* fd,size_t size){
     char* buf=new char[size];
     auto count = 1;
     auto val = fread(buf,size,count,fd);
     if(val!=count){
         std::string errorMessage=std::string("ReadData error:").append(::strerror(errno));
         LogError(errorMessage);
         throw NetReadDataException(errorMessage);
     }
     return std::make_shared<char>(size);
}


 void NetUtility::WriteData(FILE* fd,void* buf){
     auto count = 1;
     auto val = fwrite(buf,sizeof(buf),count,fd);
     if(val!=count){
         std::string errorMessage=std::string("WriteData error:").append(::strerror(errno));
         LogError(errorMessage);
         throw NetWriteDataException(errorMessage);
     }
}
 void NetUtility::WriteData(FileDescripterType fd,void* buf){
     auto fdStream=::fdopen(fd,"r");
     if(fdStream==NULL){
         std::string errorMessage=std::string("WriteData error:").append(::strerror(errno));
         LogError(errorMessage);
         throw NetWriteDataException(errorMessage);
     }
     WriteData(fdStream,buf);
}