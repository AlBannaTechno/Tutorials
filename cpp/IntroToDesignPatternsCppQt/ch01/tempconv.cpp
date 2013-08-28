// tempconv.cpp -- convert Celsius to Fahrenheit and vise versa
#include <iostream>
#include <stdexcept>
#include <string>

void show_menu();
double take_input(std::string prompt);

double to_celsius(double f);
double to_fahrenheit(double c);

int main() {
    std::cout << "Welcome to the Simple Temperature Converter!\n";
    bool exit = false;

    double val = 0;

    while (!exit) {
        show_menu();
        val = take_input("Enter menu choice: ");

        switch ((int) val) {
            case 1:
                val = take_input("Enter a Fahrenheit temperature: ");
                std::cout << "Celsius temperature is: " << to_celsius(val) << "\n\n";
                break;

            case 2:
                val = take_input("Enter a Celsius temperature: ");
                std::cout << "Fahrenheit temperature is: " << to_fahrenheit(val) << "\n\n";
                break;

            case 3:
                std::cout << "Bye!\n";
                exit = true;
                break;

            default: std::cout << "Unknown option selected.\n\n";
        }
    }
}

void show_menu() {
    std::cout << "1) Convert Fahrenheit to Celsius\n"
              << "2) Convert Celsius to Fahrenheit\n"
              << "3) Quit\n";
}

double take_input(std::string prompt) {
    std::string input;
    double val = 0;

    while (true) {
        std::cout << prompt;
        std::cin >> input;

        try {
            val = std::stod(input, 0);
            return val;
        }
        catch (std::invalid_argument &e) {
            std::cerr << "Error: non-numeric input given, please enter a number.\n";
        }
    }
}

double to_celsius(double f) {
    return ((f - 32) * 5 / 9);
}

double to_fahrenheit(double c) {
    return (c * 9 / 5 + 32);
}
