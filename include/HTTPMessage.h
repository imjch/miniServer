#ifndef HTTPMESSAGE_INC
#define HTTPMESSAGE_INC
#include <vector>
#include "HTTPMessageExtraInfo.h"
#include "HTTPMessageHeaderLocation.h"
#include "HTTPMessageHeaderDomain.h"
class HTTPMessage{
public:
	HTTPMessage()=default;
	HTTPMessage(HTTPMessageHeaderLocation& location,
                HTTPMessageHeaderDomain& headerDomains,
                HTTPMessageExtraInfo& extraInfo);
	HTTPMessageHeaderLocation& GetHTTPMessageHeaderLocation();
	HTTPMessageHeaderDomain& GetHTTPMessageHeaderDomain();
	HTTPMessageExtraInfo& GetHTTPMessageExtraInfo();

private:
	HTTPMessageHeaderLocation location;
	HTTPMessageHeaderDomain headerDomain;
	HTTPMessageExtraInfo extraInfo;
};
#endif