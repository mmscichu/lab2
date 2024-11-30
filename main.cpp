#include "Logger.h"
#include <iostream>
#include <string>

int main() {
    Logger& logger1 = Logger::getInstance();
    Logger& logger2 = Logger::getInstance();

    std::string choice;
    std::cout << "Testowanie Singletona:\n";
    std::cout << "Adres logger1: " << &logger1 << std::endl;
    std::cout << "Adres logger2: " << &logger2 << std::endl;

    while (true) {
        std::cout << "\n1. Dodaj log\n2. Wyświetl logi\n3. Wyjście\nWybierz opcję: ";
        std::cin >> choice;

        if (choice == "1") {
            std::string type, message;
            int typeChoice;
            std::cout << "Wybierz typ logu:\n1. Info\n2. Warning\n3. Error\nWybierz opcję: ";
            std::cin >> typeChoice;

            switch (typeChoice) {
                case 1:
                    type = "info";
                    break;
                case 2:
                    type = "warning";
                    break;
                case 3:
                    type = "error";
                    break;
                default:
                    std::cout << "Nieprawidłowy wybór. Ustawiam domyślnie na 'info'.\n";
                    type = "info";
            }

            std::cout << "Podaj treść logu: ";
            std::cin.ignore();
            std::getline(std::cin, message);
            
            logger1.logMessage(type, message);
        } else if (choice == "2") {
            logger1.displayLogs();
        } else if (choice == "3") {
            break;
        } else {
            std::cout << "Nieprawidłowa opcja. Spróbuj ponownie.\n";
        }
    }

    return 0;
}

