#include <stdio.h>
#include <HTTPMessageLexer.h>

int main(int argc,char**argv)
{
     HTTPMessageLexer l(argv[1]);
     l.test();
}
