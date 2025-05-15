#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int tt = 0; tt < t; tt++) {
        int n;
        cin >> n;

        long long totalSquares = 0;
        for (int i = 0; i < n; i++) {
            int ai;
            cin >> ai;
            totalSquares += ai;
        }

        // Check if the total number of squares is a perfect square
        long long squareRoot = sqrt(totalSquares);
        if (squareRoot * squareRoot == totalSquares) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
