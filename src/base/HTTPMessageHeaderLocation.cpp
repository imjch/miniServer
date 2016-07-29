#include "HTTPMessageHeaderLocation.h"
#include <unordered_map>
#include <URL.h>
#include "ServerDefine.h"
#include <regex>
#include "LogUtility.h"
HTTPMessageHeaderLocation::HTTPMessageHeaderLocation(HTTPMethod method,URLResource urlResource,Protocol protocol)
        :method(method),
         urlResource(urlResource),
         protocol(protocol) {

}

HTTPMethod HTTPMessageHeaderLocation::GetHTTPMethod() const{
    return method;
}
URLResource HTTPMessageHeaderLocation::GetURLResource() const{
    return urlResource;
}
Protocol HTTPMessageHeaderLocation::GetProtocol() const{
    return protocol;
}


 HTTPMessageHeaderLocation HTTPMessageHeaderLocation::ConstructHTTPMessageHeaderLocation(std::string& headerLocationStr){
     std::smatch smatch;
     if(ValidateHTTPMessageHeaderLocation(headerLocationStr,smatch)) {
         std::string httpMethodStr=smatch.str(1);
         HTTPMethod method = ::GetHTTPMethod(httpMethodStr);

         URLResource resource = smatch.str(2);

         std::string httpProtocolStr=smatch.str(3);
         Protocol protocol= ::GetProtocol(httpProtocolStr);

         return HTTPMessageHeaderLocation(method,resource,protocol);
     }
     else{
         std::string message("regex matching error:");
         //LogUtility::Error(message.append(headerLocationStr));
         throw std::runtime_error(message.append(headerLocationStr).append(" please ensure the correctness of your HTTP message."));
     }

 }

 bool HTTPMessageHeaderLocation::ValidateHTTPMessageHeaderLocation(const std::string& headerLocationStr,std::smatch& smatch){
     //std::string location(headerLocationStr.c_str());
    // std::transform(location.begin(),location.end(),location.begin(),::toupper);
     try {
         std::regex regex("^(GET|POST|DELETE|UPDATE) (\\S+) (HTTP1\\.0|HTTP1\\.1)$",std::regex_constants::icase);
         return std::regex_match (headerLocationStr,smatch,regex);
     }
     catch(std::regex_error& e){
         LogError(e.what());
     }
 }
