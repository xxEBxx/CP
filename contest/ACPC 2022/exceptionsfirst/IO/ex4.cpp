#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
     ifstream inFile("data.txt");
    if (!inFile) {
         cerr << "Error: Could not open data file.\n";
        return 1;
    }

    double number, sum = 0;
    int count = 0;
    while (inFile >> number) {
        sum += number;
        count++;
    }

    if (count == 0) {
         cerr << "Error: No data to analyze.\n";
        return 1;
    }

    double average = sum / count;
     cout << "Sum: " << sum << "\n";
     cout << "Average: " << average << "\n";

    inFile.close();
    return 0;
}
