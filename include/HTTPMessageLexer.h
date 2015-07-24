#ifndef HTTPMESSAGELEXER_INC
#define HTTPMESSAGELEXER_INC
#include <iostream>
#include <stdint-gcc.h>
#include <string>
class HTTPMessageLexer
{
private:
    int position;
    std::string message;
public:
    HTTPMessageLexer(const std::string message);

    void test(){
        std::cout<<this->message<<std::endl;
    }
};

#endif