#ifndef HTTPMESSAGEHANDLER_INC
#define HTTPMESSAGEHANDLER_INC
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <HTTPMessage.h>

class HTTPMessageHandler
{
private:
    HTTPMessageHeaderLocation ConstructMessageHeaderLocation( std::string&);
    std::shared_ptr<HTTPMessageHeaderDomain> ConstructMessageHeaderDomain(std::vector<std::string>::iterator begin,std::vector<std::string>::iterator end);
    HTTPMessageExtraInfo ConstructMessageExtraInfo( std::string&);
    bool ValidateMessageHeaderDomain(const HTTPMessageHeaderDomain&);
    bool ValidateMessageHeaderLocation(const HTTPMessageHeaderLocation&);
    void _ConstructMessageHeaderDomain(std::shared_ptr<HTTPMessageHeaderDomain>& messageDomain,const std::string&);
//    HTTPMessage& _ConstructHTTPMessage(const std::string& message);

public:
    HTTPMessageHandler();

    HTTPMessage ConstructHTTPMessage(const std::string& message);
};

#endif