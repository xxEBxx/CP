#include <iostream>
#include <string>
using namespace std;

int main() {
    int count = 0;
    string arr[11] = {
        "up", "up", "down", "down", "left", "right", "left", "right", "b", "a", "start"
    };
    string value;
    
    for (int k = 0; k < 11; k++) {
        cin >> value;
        
        if (arr[k] == value) {
            count++;
        }
    }
    
    cout << count << endl;
    
    return 0;
}
