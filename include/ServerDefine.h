#ifndef SERVERDEFINE_INCLUDE
#define SERVERDEFINE_INCLUDE
#include <string>
#include <LogUtility.h>
#define LISTENQ   1024
#define MAX_LINE 4096


#ifdef LOGON

#define LogError(errorMessage) LogUtility::GetInstance().Error(errorMessage, __FILE__, __LINE__)
#define LogWarn(errorMessage) LogUtility::GetInstance().Warn(errorMessage, __FILE__, __LINE__)
#define LogDebug(errorMessage) LogUtility::GetInstance().Debug(errorMessage, __FILE__, __LINE__)
#else
#define LogError(errorMessage)
#define LogWarn(errorMessage)
#define LogDebug(errorMessage)

#endif

enum ServerRole{
    HTTP,
    FILES,
};

typedef int FileDescripterType;

class HTTPMethodType
{
public:
    const static  int POST;
    const static  int GET;
    const static  int DELETE;
    const static  int UPDATE;
    const static  int FAIL;
};
typedef int HTTPMethod;


class URLSchemeType
{
public:
    static const int HTTP;
    static const int HTTPS;
    static const int FTP;
    static const int MAILTO;
    static const int FAIL;
};
typedef int URLScheme;
typedef std::string URLResource;
typedef std::string URLRequestLocation;

class ProtocolType{
public:
    static const int HTTP1_1;
    static const int HTTP1_0;
    static const int FAIL;
};
typedef int Protocol;

class HeaderDomainType{
public:
    static const int HOST;
    static const int ACCEPT;
    static const int ACCEPT_CHARSET;
    static const int ACCEPT_ENCODING;
    static const int ACCEPT_LANGUAGE;
    static const int ACCEPT_DATETIME;
    static const int CONNECTION;
    static const int COOKIE;
    static const int CONTENT_LENGTH;
    static const int CONTENT_TYPE;
    static const int REFERER;
    static const int USER_AGENT;
    static const int FAIL;
};
typedef int HTTPHeaderDomain;

Protocol GetProtocol( std::string&);
std::string GetProtocolStr(Protocol);

URLScheme GetURLScheme( std::string&);
std::string GetURLSchemeStr(URLScheme);


std::string GetHTTPMethodStr(HTTPMethod);
HTTPMethod GetHTTPMethod( std::string&);

std::string GetHeaderDomainStr(HTTPHeaderDomain);
HTTPHeaderDomain GetHeaderDomain( std::string&);



#endif