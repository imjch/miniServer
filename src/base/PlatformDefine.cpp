
#include "PlatformDefine.h"
#include <string>
#include <unordered_map>
#include <algorithm>
#include <ServerDefine.h>
#include <LogUtility.h>
#include <Exception.h>

static std::unordered_map<std::string,PlatformType > platformTable={{"PHP",PlatformType::PHP},{"JSP",PlatformType::Java}};
PlatformType GetPlatformTypeByExtName(const std::string& extName){
    std::string str(extName);
    std::transform(str.begin(),str.end(),str.begin(),::toupper);
    if(platformTable.count(str)<=0){
        std::string errMsg("no such platform corresponding extension :");
        errMsg.append(extName);
        LogError(errMsg);
        throw PlatformNotSupportedException(errMsg);
    }
    return platformTable.at(str);
}