#ifndef HTTPMESSAGEHEADERDOMAIN_INC
#define HTTPMESSAGEHEADERDOMAIN_INC
#include <string>
#include <unordered_map>
#include "ServerDefine.h"


class HTTPHeaderDomainEntity{
public:

    HTTPHeaderDomainEntity()=default;
    HTTPHeaderDomainEntity(HTTPHeaderDomain domainType,const std::string& domainInfo);
    HTTPHeaderDomain GetHTTPHeaderDomain() const;
    const std::string& GetDomainInfo() const;
private:
    HTTPHeaderDomain headerDomainKey;
    std::string headerDomainValue;
};

class HTTPMessageHeaderDomain{
public:
    typedef std::unordered_map<HTTPHeaderDomain,HTTPHeaderDomainEntity>::iterator iterator;
    typedef std::unordered_map<HTTPHeaderDomain,HTTPHeaderDomainEntity>::const_iterator const_iterator;
    HTTPMessageHeaderDomain()=default;
    void AddHTTPDomain( HTTPHeaderDomainEntity entity);
    void RemoveHTTPDomain(HTTPHeaderDomain);
    HTTPMessageHeaderDomain::iterator Begin();
    HTTPMessageHeaderDomain::iterator End();
    HTTPHeaderDomainEntity& GetHTTPHeaderDomainEntity(HTTPHeaderDomain);
private:
    std::unordered_map<HTTPHeaderDomain,HTTPHeaderDomainEntity> httpDomains;
};

HTTPHeaderDomainEntity MakeDomainEntity(HTTPHeaderDomain domainType,const std::string& domainInfo);
#endif