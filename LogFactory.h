#pragma once
#include "Log.h"
#include <memory>
#include <string>

class LogFactory
{
public:
    // Statyczna metoda tworząca odpowiedni obiekt Log na podstawie typu
    static std::unique_ptr<Log> createLog(const std::string &type, const std::string &message);
};
