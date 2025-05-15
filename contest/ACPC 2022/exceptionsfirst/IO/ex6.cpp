#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main() {
     ifstream inFile("textfile.txt");
    if (!inFile) {
         cerr << "Error: Could not open file.\n";
        return 1;
    }

    int wordCount = 0;
     string line, word;

    while ( getline(inFile, line)) {
         istringstream iss(line);
        while (iss >> word) {
            wordCount++;
        }
    }

    inFile.close();
     cout << "The file contains " << wordCount << " words.\n";
    return 0;
}
