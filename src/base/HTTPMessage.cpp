#include "HTTPMessage.h"
#include "HTTPMessageExtraInfo.h"
#include "HTTPMessageHeaderLocation.h"
#include "HTTPMessageHeaderDomain.h"
HTTPMessage::HTTPMessage(HTTPMessageHeaderLocation& location,
                         HTTPMessageHeaderDomain& headerDomain,
                         HTTPMessageExtraInfo& extraInfo):
        location(location),
        headerDomain(headerDomain),
        extraInfo(extraInfo)
{

}


HTTPMessageHeaderLocation& HTTPMessage::GetHTTPMessageHeaderLocation(){
    return location;
}
HTTPMessageHeaderDomain& HTTPMessage::GetHTTPMessageHeaderDomain(){
    return headerDomain;
}
HTTPMessageExtraInfo& HTTPMessage::GetHTTPMessageExtraInfo(){
    return extraInfo;
}