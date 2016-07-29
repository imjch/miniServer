#ifndef HTTPMESSAGEHEADERLOCATION_INC
#define HTTPMESSAGEHEADERLOCATION_INC
#include "URL.h"
#include "ServerDefine.h"
#include <regex>
class HTTPMessageHeaderLocation{
public:
    HTTPMessageHeaderLocation()= default;
    HTTPMessageHeaderLocation(HTTPMethod method,URLResource url,Protocol protocol);
    HTTPMethod GetHTTPMethod() const;
    URLResource GetURLResource() const;
    Protocol GetProtocol() const;

    static HTTPMessageHeaderLocation ConstructHTTPMessageHeaderLocation(std::string&);
private:
    static bool ValidateHTTPMessageHeaderLocation(const std::string&,std::smatch&);

    HTTPMethod method;
    URLResource urlResource;
    Protocol protocol;
};
#endif