#ifndef HTTPEXECUTOR_INCLUDE
#define HTTPEXECUTOR_INCLUDE

#include "HTTPMessage.h"
#include "HTTPMessageHeaderLocation.h"
#include "HTTPMessageHeaderDomain.h"
class HTTPExecutor{
public:
    HTTPExecutor()=default;
    HTTPExecutor(HTTPMessage& message);

private:
    void ProcessHeaderLocation(HTTPMessageHeaderLocation& location);
    void ProcessHeaderDomains(HTTPMessageHeaderDomain& domains);
    void ProcessHeaderExtraInfo(HTTPMessageExtraInfo& extraInfo);
    HTTPMessage http;
};
#endif