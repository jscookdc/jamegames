#pragma once

#include <glog/logging.h>

#define U8(x) (static_cast<int>(x))
#define LOG_DEBUG DLOG(INFO)
#define LOG_WARNING LOG(WARNING)
#define LOG_ERROR LOG(ERROR)
#define LOG_FATAL LOG(FATAL)