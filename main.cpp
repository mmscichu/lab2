#include "Logger.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <locale.h>

// Funkcja pomocnicza do konwersji stringa na małe litery
std::string toLower(std::string s)
{
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c)
                   { return std::tolower(c); });
    return s;
}

int main()
{
    // W Windows brakowało polskich znaków
    setlocale(LC_ALL, "pl_PL.UTF-8");
    // Pobieranie instancji Logger'a w celu zaprezentowania działania klasy Logger wedlug wzorca Singleton
    Logger &logger1 = Logger::getInstance();
    Logger &logger2 = Logger::getInstance();

    // Demonstracja, że obie zmienne odnoszą się do tej samej instancji
    std::cout << "Testowanie Singletona:\n";
    std::cout << "Adres logger1: " << &logger1 << std::endl;
    std::cout << "Adres logger2: " << &logger2 << std::endl;

    // Testowanie operacji na loggerze
    logger1.logMessage("info", "Test message 1");
    logger2.logMessage("warning", "Test message 2");

    std::cout << "\nWyświetlanie logów przez logger1:\n";
    logger1.displayLogs();

    std::cout << "\nWyświetlanie logów przez logger2:\n";
    logger2.displayLogs();

    std::string choice;
    while (true)
    {
        // Menu użytkownika
        std::cout << "\n1. Dodaj log\n2. Wyświetl logi\n3. Wyjście\nWybierz opcję: ";
        std::cin >> choice;

        // Dodawanie nowego logu
        if (choice == "1")
        {
            std::string type, message, typeInput;
            // Wybór typu logu
            std::cout << "Wybierz typ logu:\n1. Info\n2. Warning\n3. Error\nWybierz opcję: ";
            std::cin >> typeInput;
            typeInput = toLower(typeInput); // Zabezpieczenie przed różnymi wielkościami liter

            // Wybór typu logu na podstawie wejścia użytkownika
            if (typeInput == "1" || typeInput == "info")
            {
                type = "info";
            }
            else if (typeInput == "2" || typeInput == "warning")
            {
                type = "warning";
            }
            else if (typeInput == "3" || typeInput == "error")
            {
                type = "error";
            }
            else
            {
                std::cout << "Nieprawidłowy wybór. Ustawiam domyślnie na 'info'.\n";
                type = "info";
            }

            std::cout << "Podaj treść logu: ";
            std::cin.ignore();
            std::getline(std::cin, message);

            logger1.logMessage(type, message);
        }
        else if (choice == "2")
        {
            // Wyświetlanie wszystkich logów
            logger1.displayLogs();
        }
        else if (choice == "3")
        {
            // Wyjście z programu
            break;
        }
        else
        {
            // Na wypadek błędnego wpisu
            std::cout << "Nieprawidłowa opcja. Spróbuj ponownie.\n";
        }
    }

    return 0;
}
