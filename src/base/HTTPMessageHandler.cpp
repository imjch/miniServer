#include <HTTPMessageHandler.h>
#include <string>
#include <boost/algorithm/string/split.hpp>
#include <unordered_map>
#include <regex>
#include <boost/algorithm/string.hpp>
#include <HTTPMessage.h>
#include "LogUtility.h"
#include <memory>
HTTPMessageHandler::HTTPMessageHandler() {
}

HTTPMessage HTTPMessageHandler::ConstructHTTPMessage(const std::string& message) {
    assert(message.size()>0);
    std::vector<std::string> messageItems;
    auto begin =std::sregex_iterator(message.begin(),message.end(),std::regex("([^\\n|^\\r\\n]+)",std::regex_constants::icase));
    auto end = std::sregex_iterator();
    for(auto i = begin ; i!=end; i++) {
       messageItems.push_back(i->str());
    }
    //std::for_each(messageItems.begin(),messageItems.end(),[](const std::string& str){ std::cout<<str<<std::endl;});
    assert(messageItems.size() >= 1);
    auto mBegin = messageItems.begin();
    auto mEnd = messageItems.end();
    auto headerLocation = ConstructMessageHeaderLocation(*mBegin++);//handle first line of http
    auto headerDomain = ConstructMessageHeaderDomain(mBegin, mEnd);//handle all header domains located at messageItems, from 1 to length-2
    auto extraInfo = ConstructMessageExtraInfo(*--mEnd);//handle http info located at length-1
    return HTTPMessage(headerLocation, *headerDomain, extraInfo);
}
bool HTTPMessageHandler::ValidateMessageHeaderDomain(const HTTPMessageHeaderDomain& headerDomain){
    throw std::runtime_error(std::string("ValidateMessageHeaderDomain not implemented").append((std::to_string(__LINE__))));
}
bool HTTPMessageHandler::ValidateMessageHeaderLocation(const HTTPMessageHeaderLocation& headerLocation){
    throw std::runtime_error(std::string("ValidateMessageHeaderLocation not implemented").append((std::to_string(__LINE__))));
}

//HTTPMessage& HTTPMessageHandler::_ConstructHTTPMessage(const std::string& message){
//
//}

HTTPMessageHeaderLocation HTTPMessageHandler::ConstructMessageHeaderLocation(std::string& headerLocation) {
    return HTTPMessageHeaderLocation::ConstructHTTPMessageHeaderLocation(headerLocation);
}

 void HTTPMessageHandler::_ConstructMessageHeaderDomain( std::shared_ptr<HTTPMessageHeaderDomain>& messageDomain,const std::string & headerDomain) {
     std::pair<HTTPHeaderDomain ,std::string> domainPair;
     std::regex regex("^(\\S+): (.+)$",std::regex_constants::icase);
     std::smatch m;
     if(!std::regex_match(headerDomain,m,regex)){
         LogError(std::string("HeaderDomain error: ").append(headerDomain));
         throw std::runtime_error(std::string("regex matching error:").append(headerDomain));
     }
     else{
         std::string domainStr=m[1];
         messageDomain->AddHTTPDomain(MakeDomainEntity(GetHeaderDomain(domainStr),m[2]));
     }
}

HTTPMessageExtraInfo HTTPMessageHandler::ConstructMessageExtraInfo( std::string& extraInfo){
    LogError("ConstructMessageExtraInfo not implemented");
}

std::shared_ptr<HTTPMessageHeaderDomain> HTTPMessageHandler::ConstructMessageHeaderDomain(
std::vector<std::string>::iterator begin, std::vector<std::string>::iterator end) {
    std::shared_ptr<HTTPMessageHeaderDomain> messageHeaderDomainSPtr(new HTTPMessageHeaderDomain);
    std::for_each(begin, end, [this, &messageHeaderDomainSPtr](const std::string &str) {
        this->_ConstructMessageHeaderDomain(messageHeaderDomainSPtr, str);
    });
    return messageHeaderDomainSPtr;
}

