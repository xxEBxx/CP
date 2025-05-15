#include <iostream>
#include <fstream>
#include <stdexcept>

int main() {
    std::string filename;
    std::cout << "Enter the file name to open: ";
    std::cin >> filename;

    try {
        std::ifstream file(filename);
        if (!file) {
            throw std::runtime_error("File does not exist.");
        }
        std::cout << "File opened successfully!" << std::endl;
        file.close();
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

