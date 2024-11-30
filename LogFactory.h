#pragma once
#include "Log.h"
#include <memory>
#include <string>

class LogFactory {
public:
    static std::unique_ptr<Log> createLog(const std::string& type, const std::string& message);
};

