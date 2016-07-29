#include <unordered_map>
#include <assert.h>
#include "ServerDefine.h"
#include <algorithm>
#include <LogUtility.h>

const int URLSchemeType::HTTP=0;
const int URLSchemeType::HTTPS=1;
const int URLSchemeType::FTP=2;
const int URLSchemeType::MAILTO=3;
const int URLSchemeType::FAIL=-1;


const int HTTPMethodType::POST=0;
const int HTTPMethodType::GET=1;
const int HTTPMethodType::DELETE=2;
const int HTTPMethodType::UPDATE=3;
const int HTTPMethodType::FAIL=-1;

const int ProtocolType::HTTP1_0=0;
const int ProtocolType::HTTP1_1=1;
const int ProtocolType::FAIL=-1;


 const int HeaderDomainType::HOST=0;
 const int HeaderDomainType::ACCEPT=1;
 const int HeaderDomainType::ACCEPT_CHARSET=2;
 const int HeaderDomainType::ACCEPT_ENCODING=3;
 const int HeaderDomainType::ACCEPT_LANGUAGE=4;
 const int HeaderDomainType::ACCEPT_DATETIME=5;
 const int HeaderDomainType::CONNECTION=6;
 const int HeaderDomainType::COOKIE=7;
 const int HeaderDomainType::CONTENT_LENGTH=8;
 const int HeaderDomainType::CONTENT_TYPE=9;
 const int HeaderDomainType::REFERER=10;
 const int HeaderDomainType::USER_AGENT=11;
 const int HeaderDomainType::FAIL=-1;

std::string _GetTypeStr(std::unordered_map<int,std::string> strTable,int type){
    if(strTable.count(type)>0){
        return strTable.at(type);
    }
    else{
        LogError(std::string("no corresponding string: ").append(std::to_string(type)));
        throw std::runtime_error(std::string("no corresponding string: ").append(std::to_string(type)));
    }
}

int _GetType(std::unordered_map<std::string,int> typeTable, std::string& str){
    assert(str.size()!=0);
    std::transform(str.begin(),str.end(),str.begin(),::toupper);
    if(typeTable.count(str)>0){
        return typeTable.at(str);
    }
    else{
        LogError(std::string("no corresponding type: ").append(str));
        throw std::runtime_error(std::string("no corresponding string: ").append(str));
    }
}

std::string GetURLSchemeStr(URLScheme scheme){
    static std::unordered_map<URLScheme,std::string> schemeStrTable={{URLSchemeType::HTTP,"HTTP"},{URLSchemeType::HTTPS,"HTTPS"},{URLSchemeType::FTP,"FTP"},{URLSchemeType::MAILTO,"MAILTO"}};
    return _GetTypeStr(schemeStrTable,scheme);
}

URLScheme GetURLScheme(std::string& scheme){
    static std::unordered_map<std::string,URLScheme> schemeTable={{"HTTP",URLSchemeType::HTTP},{"HTTPS",URLSchemeType::HTTPS},{"FTP",URLSchemeType::FTP},{"MAILTO",URLSchemeType::MAILTO}};
    return _GetType(schemeTable,scheme);
}

std::string GetHTTPMethodStr(HTTPMethod method){
   static std::unordered_map<HTTPMethod,std::string> methodStrTable={{HTTPMethodType::POST,"POST"},{HTTPMethodType::GET,"GET"},{HTTPMethodType::DELETE,"DELETE"},{HTTPMethodType::UPDATE,"UPDATE"}};
    return  _GetTypeStr(methodStrTable,method);
}

HTTPMethod GetHTTPMethod( std::string& method){
    static std::unordered_map<std::string,HTTPMethod> methodTable={{"POST",HTTPMethodType::POST},{"GET",HTTPMethodType::GET},{"DELETE",HTTPMethodType::DELETE},{"UPDATE",HTTPMethodType::UPDATE}};
    return _GetType(methodTable,method);
}

Protocol GetProtocol( std::string& protocol){
    static std::unordered_map<std::string,Protocol> protocolTable={{"HTTP1_0",ProtocolType::HTTP1_0},{"HTTP1_1",ProtocolType::HTTP1_1}};
    std::string proto(protocol);
    std::replace(proto.begin(),proto.end(),'.','_');
    return _GetType(protocolTable,proto);
}
std::string GetProtocolStr(Protocol protocol){
    static std::unordered_map<Protocol,std::string> protocolStrTable={{ProtocolType::HTTP1_0,"HTTP1_0"},{ProtocolType::HTTP1_1,"HTTP1_1"}};
    return _GetTypeStr(protocolStrTable,protocol);
}



std::string GetHeaderDomainStr(HTTPHeaderDomain domain){
    static std::unordered_map<HTTPHeaderDomain,std::string> domainStrTable={
            {HeaderDomainType::HOST,"HOST"},
            {HeaderDomainType::ACCEPT,"ACCEPT"},
            {HeaderDomainType::ACCEPT_CHARSET,"ACCEPT-CHARSET"},
            {HeaderDomainType::ACCEPT_ENCODING,"ACCEPT-ENCODING"},
            {HeaderDomainType::ACCEPT_LANGUAGE,"ACCEPT-LANGUAGE"},
            {HeaderDomainType::ACCEPT_DATETIME,"ACCEPT-DATETIME"},
            {HeaderDomainType::CONNECTION,"CONNECTION"},
            {HeaderDomainType::COOKIE,"COOKIE"},
            {HeaderDomainType::CONTENT_LENGTH,"CONTENT-LENGTH"},
            {HeaderDomainType::CONTENT_TYPE,"CONTENT-TYPE"},
            {HeaderDomainType::REFERER,"REFERER"},
            {HeaderDomainType::USER_AGENT,"USER-AGENT"}
    };
    return  _GetTypeStr(domainStrTable,domain);
}
HTTPHeaderDomain GetHeaderDomain( std::string& domain){
    static std::unordered_map<std::string,HTTPHeaderDomain> domainTable={
            {"HOST",HeaderDomainType::HOST},
            {"ACCEPT",HeaderDomainType::ACCEPT},
            {"ACCEPT-CHARSET",HeaderDomainType::ACCEPT_CHARSET},
            {"ACCEPT-ENCODING",HeaderDomainType::ACCEPT_ENCODING},
            {"ACCEPT-LANGUAGE",HeaderDomainType::ACCEPT_LANGUAGE},
            {"ACCEPT-DATETIME",HeaderDomainType::ACCEPT_DATETIME},
            {"CONNECTION",HeaderDomainType::CONNECTION},
            {"COOKIE",HeaderDomainType::COOKIE},
            {"CONTENT-LENGTH",HeaderDomainType::CONTENT_LENGTH},
            {"CONTENT-TYPE",HeaderDomainType::CONTENT_TYPE},
            {"REFERER",HeaderDomainType::REFERER},
            {"USER-AGENT",HeaderDomainType::USER_AGENT}
    };
    return _GetType(domainTable,domain);
}



