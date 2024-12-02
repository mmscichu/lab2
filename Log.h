#pragma once
#include <string>

// Abstrakcyjna klasa bazowa dla wszystkich typów logów
class Log
{
public:
    // Wirtualne metody do pobrania wiadomości i typu logu
    virtual std::string getMessage() const = 0;
    virtual std::string getType() const = 0;
    // Destruktor
    virtual ~Log() = default;
};

class InfoLog : public Log
{
private:
    std::string message;

public:
    InfoLog(const std::string &msg);
    // Implementacje metod wirtualnych z klasy bazowej
    std::string getMessage() const override;
    std::string getType() const override;
};

class WarningLog : public Log
{
private:
    std::string message;

public:
    WarningLog(const std::string &msg);
    std::string getMessage() const override;
    std::string getType() const override;
};

class ErrorLog : public Log
{
private:
    std::string message;

public:
    ErrorLog(const std::string &msg);
    std::string getMessage() const override;
    std::string getType() const override;
};
