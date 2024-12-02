#pragma once
#include "Log.h"
#include "LogFactory.h"
#include <vector>
#include <mutex>
#include <memory>

class Logger
{
private:
    // Prywatny konstruktor zapobiega tworzeniu instancji z zewnątrz
    Logger();
    // Wektor przechowujący logi
    std::vector<std::unique_ptr<Log>> logs;
    std::mutex mutex;

    // Statyczna instancja Singletona
    static Logger *instance;

public:
    // Usunięcie konstruktora kopiującego i operatora przypisania zapobiega tworzeniu kopii - wzorzec Singleton
    Logger(const Logger &) = delete;
    Logger &operator=(const Logger &) = delete;

    // Metoda zwracająca instancję Singletona
    static Logger &getInstance();
    // Metoda do dodawania nowych logów
    void logMessage(const std::string &type, const std::string &message);
    // Metoda do wyświetlania wszystkich logów
    void displayLogs();
};
