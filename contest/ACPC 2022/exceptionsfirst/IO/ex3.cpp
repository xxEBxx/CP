#include <iostream>
#include <fstream>
using namespace std;

int main() {
     ifstream inFile("input.txt");
    if (!inFile) {
         cerr << "Error: Input file does not exist.\n";
        return 1;
    }

     ofstream outFile("output_copy.txt");
    if (!outFile) {
         cerr << "Error: Could not create output file.\n";
        return 1;
    }

     string line;
    while ( getline(inFile, line)) {
        outFile << line << "\n";
    }

    inFile.close();
    outFile.close();
     cout << "File copied successfully.\n";
    return 0;
}
