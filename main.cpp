#include <iostream>
#include <vector>
#include <string>
#include <mutex>

class Logger {
private:
    // Prywatny konstruktor uniemożliwia tworzenie instancji z zewnątrz klasy
    Logger() {}
    
    // Wektor przechowujący logi
    std::vector<std::string> logs;
    
    std::mutex mutex;
    
    // Statyczna instancja klasy Logger. Przechowuje jedyną instancję Loggera w całym programie
    static Logger* instance;

public:
    // Usunięcie konstruktora kopiującego i operatora przypisania. Zapobiega to tworzeniu kopii Singletona, co mogłoby naruszyć jego unikalność
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
    
    // Statyczna metoda zwracająca referencję do jedynej instancji Loggera
    static Logger& getInstance() {
        if (instance == nullptr) {
            instance = new Logger();
        }
        return *instance;
    }
    
    // Metoda do dodawania nowego logu
    void logMessage(const std::string& message) {
        std::lock_guard<std::mutex> lock(mutex);
        logs.push_back(message);
    }
    
    // Metoda do wyświetlania wszystkich logów
    void displayLogs() {
        std::lock_guard<std::mutex> lock(mutex);
        for (const auto& log : logs) {
            std::cout << log << std::endl;
        }
    }
};

// Inicjalizacja statycznej instancji
Logger* Logger::instance = nullptr;

int main() {
    // Pobranie instancji Loggera
    Logger& logger1 = Logger::getInstance();
    Logger& logger2 = Logger::getInstance();
    
    // Dodanie logów przez różne "instancje". Póżniej zademonstruje, że obie referencje odnoszą się do tej samej instancji
    logger1.logMessage("Log z logger1");
    logger2.logMessage("Log z logger2");
    
    // Wyświetlenie adresów obu referencji
    // Potwierdza, że obie referencje wskazują na tę samą instancję w pamięci
    std::cout << "Adres logger1: " << &logger1 << std::endl;
    std::cout << "Adres logger2: " << &logger2 << std::endl;
    
    // Wyświetlenie wszystkich logów
    // Pokazuje, że logi dodane przez obie referencje są przechowywane w tej samej instancji
    logger1.displayLogs();
    
    return 0;
}

