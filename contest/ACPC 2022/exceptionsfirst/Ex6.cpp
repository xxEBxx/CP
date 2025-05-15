#include <iostream>
#include <stdexcept>
#include <limits>

void first() {
    try {
        second();
    } catch (const std::runtime_error& e) {
        cerr << "Caught exception in first(): " << e.what() << std::endl;
        throw;
    }
}

void second() {
    third();
}

void third() {
    throw std::runtime_error("Exception thrown in third()"); // Throw an exception
}

int main() {
    try {
        first(); // Call the first function
    } catch (const std::exception& e) {
        // Handle any unhandled exceptions from the call stack
        std::cerr << "Caught exception in main(): " << e.what() << std::endl;
    }
    return 0;
}
