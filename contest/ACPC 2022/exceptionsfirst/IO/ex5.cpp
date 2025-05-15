#include <iostream>
#include <fstream>
using namespace std;

int main() {
     ofstream outFile("output.txt",  ios::app);
    if (!outFile) {
         cerr << "Error: Could not open file for appending.\n";
        return 1;
    }

    outFile << "This is additional information appended to the file.\n";
    outFile.close();
     cout << "Data appended successfully.\n";
    return 0;
}
