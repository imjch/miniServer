//
// Created by jc on 15-8-19.
//

#ifndef URL_INC
#define URL_INC
#include <string>
#include <regex>
#include <unordered_map>
#include <cassert>
#include "ServerDefine.h"

class URL {
public:

    //URL()=default;
    URL(URLScheme,URLRequestLocation,URLResource);
    URLRequestLocation GetURLRequestLocation();
    URLResource GetURLResource();
    URLScheme GetURLScheme();

    static URL ConstructURL(const std::string&);
private:
    static bool ValidateURL(std::string,std::smatch& sm);


    void SetURLScheme(URLScheme);
    void SetURLRequestLocation(const URLRequestLocation&);
    void SetURLResource(const URLResource&);


    //std::string url;
    URLScheme scheme;
    URLRequestLocation requestLocation;
    URLResource resource;
};


#endif //PROJECT_URL_H
