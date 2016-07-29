#ifndef PLATFORMDISPATCHER_INCLUDE
#define PLATFORMDISPATCHER_INCLUDE
#include <boost/noncopyable.hpp>
#include <memory>
#include "PlatformProcessor.h"
#include "PlatformDefine.h"
class PlatformDispatcher:public boost::noncopyable{
public:
    typedef std::shared_ptr<PlatformProcessor> DispatcherProcessorPtr;
    static DispatcherProcessorPtr DispatchPlatformProcessor(PlatformType extType);
private:
};

#endif