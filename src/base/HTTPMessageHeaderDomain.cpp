#include "HTTPMessageHeaderDomain.h"

HTTPHeaderDomainEntity::HTTPHeaderDomainEntity(HTTPHeaderDomain domainType,const std::string& domainInfo):
        headerDomainKey(domainType),
        headerDomainValue(domainInfo)
{

}



HTTPHeaderDomain HTTPHeaderDomainEntity::GetHTTPHeaderDomain() const{
    return this->headerDomainKey;
}

const std::string& HTTPHeaderDomainEntity::GetDomainInfo() const{
    return this->headerDomainValue;
}


void HTTPMessageHeaderDomain::AddHTTPDomain( HTTPHeaderDomainEntity entity){
    //httpDomains.insert(std::make_pair(entity.getHTTPHeaderDomain(),entity));
    httpDomains[entity.GetHTTPHeaderDomain()]=entity;
}

void HTTPMessageHeaderDomain::RemoveHTTPDomain(HTTPHeaderDomain domain){
    httpDomains.erase(domain);
}

HTTPMessageHeaderDomain::iterator HTTPMessageHeaderDomain::Begin(){
    return httpDomains.begin();
}
HTTPMessageHeaderDomain::iterator HTTPMessageHeaderDomain::End(){
    return httpDomains.end();
}
HTTPHeaderDomainEntity& HTTPMessageHeaderDomain::GetHTTPHeaderDomainEntity(HTTPHeaderDomain domain){
    auto iterEntity = httpDomains.find(domain);
    if(iterEntity!=httpDomains.end()){
        throw std::runtime_error("no such HeaderDomainEntity represented by " + GetHeaderDomainStr(domain));
    }
    return iterEntity->second;
}

HTTPHeaderDomainEntity MakeDomainEntity(HTTPHeaderDomain domainType,const std::string& domainInfo){
    return HTTPHeaderDomainEntity(domainType,domainInfo);
}
