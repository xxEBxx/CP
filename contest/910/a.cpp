#include <iostream>
#include <string>
using namespace std;

int countB(string s) {
    int count = 0;
    for (char i : s) {
        if (i == 'B') {
            count++;
        }
    }
    return count;
}

int main() {
    int t, n, k, m, diff, index, diffc;
    string s;
    cin >> t;

    for (int j = 0; j < t; j++) {
        m = 0;
        index = 0;
        cin >> n >> k;

        // Ignore the newline character in the buffer
        cin.ignore();

        getline(cin, s);
        diff = k - countB(s);
        diffc = diff;

        if (diff == 0) {
            cout << 0 << endl;
            continue;  // Use continue instead of break
        }

        while (diff < 0) {
            if (s[index] == 'B') {
                diff++;
            }
            index++;
        }

        while (diff > 0) {
            if (s[index] == 'A') {
                diff--;
            }
            index++;
        }
        cout<<1<<endl;
        cout << index;

        if (diffc < 0) {
            cout << " A" << endl;
            continue;  
        }

        cout << " B" << endl;
    }

    return 0;
}
