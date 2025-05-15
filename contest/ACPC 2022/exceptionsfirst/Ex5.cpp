#include <iostream>
#include <stdexcept>
#include <limits>
using namespace std;
void performOperations(int a, int b) {
    if (b == 0) {
        throw  runtime_error("Division by zero.");
    }
    if (a >  numeric_limits<int>::max() - b) {
        throw  overflow_error("Overflow detected in addition.");
    }
     cout << "Addition: " << a + b <<  endl;
     cout << "Division: " << a / b <<  endl;
}

int main() {
    int a, b;
     cout << "Enter two integers: ";
     cin >> a >> b;

    try {
        performOperations(a, b);
    } catch (const  runtime_error& e) {
         cerr << "Runtime Error: " << e.what() <<  endl;
    } catch (const  overflow_error& e) {
         cerr << "Overflow Error: " << e.what() <<  endl;
    }

    return 0;
}
