#pragma once
#include "Log.h"
#include "LogFactory.h"
#include <vector>
#include <mutex>
#include <memory>

class Logger {
private:
    Logger();
    std::vector<std::unique_ptr<Log>> logs;
    std::mutex mutex;
    static Logger* instance;

public:
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    static Logger& getInstance();
    void logMessage(const std::string& type, const std::string& message);
    void displayLogs();
};

