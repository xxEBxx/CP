#include<iostream>

using namespace std;

int main() {
    int t, n, d, f, count, i;
    cin >> t >> n;
    cin.ignore();
    string s;
    getline(cin, s);
    
    for (int k = 0; k < n; k++) {
        count = 0;
        cin >> d >> f;
        i = d;
        while (i < f) {
            if (s[i - 1] == 'A' && s[i] == 'C') {
                count++;
                i++;
            }
            i++;
        }
        cout << count << endl;  // Output the count on a new line for each test case
    }

    return 0;
}
/*8 3
ACACTACG
3 7
2 3
1 8*/