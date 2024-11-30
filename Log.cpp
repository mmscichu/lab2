#include "Log.h"

InfoLog::InfoLog(const std::string& msg) : message(msg) {}
std::string InfoLog::getMessage() const { return message; }
std::string InfoLog::getType() const { return "INFO"; }

WarningLog::WarningLog(const std::string& msg) : message(msg) {}
std::string WarningLog::getMessage() const { return message; }
std::string WarningLog::getType() const { return "WARNING"; }

ErrorLog::ErrorLog(const std::string& msg) : message(msg) {}
std::string ErrorLog::getMessage() const { return message; }
std::string ErrorLog::getType() const { return "ERROR"; }

