#include <Exception.h>
#include <iostream>
#include "HTTPExecutor.h"

HTTPExecutor::HTTPExecutor(HTTPMessage& message):http(message) {

}
void HTTPExecutor::ProcessHeaderLocation(HTTPMessageHeaderLocation& location){
    std::cout<<location.GetProtocol()<<std::endl;
    std::cout<<location.GetProtocol()<<std::endl;
    std::cout<<location.GetURLResource()<<std::endl;
}

void HTTPExecutor::ProcessHeaderDomains(HTTPMessageHeaderDomain& domains) {
    throw NotImplementedException("");
}

void HTTPExecutor::ProcessHeaderExtraInfo(HTTPMessageExtraInfo& extraInfo){

    throw NotImplementedException("");
}