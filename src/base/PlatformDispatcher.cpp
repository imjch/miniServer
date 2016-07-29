#include "PlatformDispatcher.h"
#include "PlatformDefine.h"
#include <algorithm>

PlatformDispatcher::DispatcherProcessorPtr PlatformDispatcher::DispatchPlatformProcessor(PlatformType platformType) {
    switch (platformType) {
        case PlatformType::Java:
            return DispatcherProcessorPtr(new JavaPlatformProcessor);
        case PlatformType::PHP:
            return DispatcherProcessorPtr(new PHPPlatformProcessor);
    }
}