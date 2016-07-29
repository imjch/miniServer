//
// Created by jc on 15-8-19.
//
#include <string>
#include <algorithm>

#include <URL.h>
#include <regex>
#include <cassert>
#include <iostream>
#include "ServerDefine.h"



URL::URL(URLScheme scheme,URLRequestLocation requestLocation,URLResource urlResource):
        scheme(scheme),
        requestLocation(requestLocation),
        resource(urlResource){

}
void URL::SetURLScheme(URLScheme scheme){
    this->scheme=scheme;
}
void URL::SetURLRequestLocation(const URLRequestLocation& requestLocation){
    this->requestLocation=requestLocation;
}
void URL::SetURLResource(const URLResource& resource){
    this->resource=resource;
}

URLScheme URL::GetURLScheme(){
    return this->scheme;
}
URLRequestLocation URL::GetURLRequestLocation(){
    return this->requestLocation;
}

URLResource URL::GetURLResource(){
    return this->resource;
}

URL URL::ConstructURL(const std::string& url) {
    std::smatch sm;
    if(ValidateURL(url,sm))
    {
        std::string urlSchemeStr=sm.str(1);
        return URL(::GetURLScheme(urlSchemeStr),sm.str(2),sm.str(3));
    }
}

bool URL::ValidateURL(std::string url,std::smatch& sm) {
    std::transform(url.begin(),url.end(),url.begin(),::toupper);
    std::regex regex("(HTTP|HTTPS|FTP)://(WWW.BAIDU.COM)",std::regex_constants::icase);
    std::string::iterator i = std::remove_if(url.begin(),url.end(),[](char x)->bool{return x==' ';});
    url.erase(i,url.end());
    return std::regex_search (url,sm,regex);
}