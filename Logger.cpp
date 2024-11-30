#include "Logger.h"
#include <iostream>

Logger* Logger::instance = nullptr;

Logger::Logger() {}

Logger& Logger::getInstance() {
    if (instance == nullptr) {
        instance = new Logger();
    }
    return *instance;
}

void Logger::logMessage(const std::string& type, const std::string& message) {
    std::lock_guard<std::mutex> lock(mutex);
    logs.push_back(LogFactory::createLog(type, message));
}

void Logger::displayLogs() {
    std::lock_guard<std::mutex> lock(mutex);
    for (const auto& log : logs) {
        std::cout << "[" << log->getType() << "] " << log->getMessage() << std::endl;
    }
}

