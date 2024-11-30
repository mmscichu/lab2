#include "LogFactory.h"
#include <stdexcept>

std::unique_ptr<Log> LogFactory::createLog(const std::string& type, const std::string& message) {
    if (type == "info") return std::make_unique<InfoLog>(message);
    if (type == "warning") return std::make_unique<WarningLog>(message);
    if (type == "error") return std::make_unique<ErrorLog>(message);
    throw std::invalid_argument("Unknown log type");
}

