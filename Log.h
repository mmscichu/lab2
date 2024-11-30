#pragma once
#include <string>

class Log {
public:
    virtual std::string getMessage() const = 0;
    virtual std::string getType() const = 0;
    virtual ~Log() = default;
};

class InfoLog : public Log {
private:
    std::string message;
public:
    InfoLog(const std::string& msg);
    std::string getMessage() const override;
    std::string getType() const override;
};

class WarningLog : public Log {
private:
    std::string message;
public:
    WarningLog(const std::string& msg);
    std::string getMessage() const override;
    std::string getType() const override;
};

class ErrorLog : public Log {
private:
    std::string message;
public:
    ErrorLog(const std::string& msg);
    std::string getMessage() const override;
    std::string getType() const override;
};

