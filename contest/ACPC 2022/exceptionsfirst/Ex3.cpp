#include <iostream>
#include <stdexcept>

class NegativeNumberException : public std::exception {
public:
    const char* what() const noexcept override {
            return "Negative numbers are not allowed.";
    }
};

void checkNumber(int number) {
    if (number < 0) {
        throw NegativeNumberException();
    }
    std::cout << "Number is valid: " << number << std::endl;
}

int main() {
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;

    try {
        checkNumber(number);
    } catch (const NegativeNumberException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
