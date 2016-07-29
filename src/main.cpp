#include <iostream>
#include <HTTPServer.h>
#include <LogUtility.h>
#include "string_utility.h"
#include <netdb.h>
#include <arpa/inet.h>
#include <FileServer.h>
#include "MultiRoleServer.h"
#include "Configuration.h"

int main(int argc,char**argv) {

    RoleServer server = ConstructServer();
    server->Start();

}
