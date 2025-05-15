#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
       ifstream inFile("output.txt");
    if (!inFile) {
           cerr << "Error: Could not open file for reading.\n";
        return 1;
    }

       string line;
    while (   getline(inFile, line)) {
           cout << line <<    endl;
    }

    inFile.close();
    return 0;
}
