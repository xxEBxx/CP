#include <iostream>
#include <fstream>
using namespace std;
int main() {
      ofstream outFile("output.txt");
    if (!outFile) {
          cerr << "Error: Could not open file for writing.\n";
        return 1;
    }

    outFile << "Hello, my name is John Doe.\n";
    outFile << "I am 20 years old.\n";
    outFile << "The value of Pi is approximately 3.14.\n";

    outFile.close();
      cout << "Data written to file successfully.\n";
    return 0;
}
