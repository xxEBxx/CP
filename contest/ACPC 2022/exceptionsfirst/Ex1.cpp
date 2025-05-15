#include <iostream>
#include <stdexcept>

int main() {
    int numerator, denominator;
    std::cout << "Enter numerator: ";
    std::cin >> numerator;
    std::cout << "Enter denominator: ";
    std::cin >> denominator;

    try {
        if (denominator == 0) {
            throw std::runtime_error("Division by zero is not allowed.");
        }
        std::cout << "Result: " << numerator / denominator << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
