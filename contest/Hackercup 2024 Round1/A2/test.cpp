#include <iostream>
#include <fstream>

int main() {
    // Open input.txt for reading
    std::ifstream inFile("input.txt");
    if (!inFile) {
        std::cerr << "Error opening input.txt. Please check the file path!" << std::endl;
        return 1;
    }

    // Open output.txt for writing
    std::ofstream outFile("output.txt");
    if (!outFile) {
        std::cerr << "Error opening output.txt. Please check the file path!" << std::endl;
        return 1;
    }

    // Redirect cin and cout
    std::cin.rdbuf(inFile.rdbuf());
    std::cout.rdbuf(outFile.rdbuf());

    // Example of using cin and cout
    int a, b;
    std::cin >> a >> b;  // Input is now read from input.txt
    std::cout << "Sum: " << a + b << std::endl;  // Output is written to output.txt

    return 0;
}
