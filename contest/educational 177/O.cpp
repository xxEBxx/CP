#include <iostream>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int white = 0, black = 0;
    for (int i = 0; i < K; ++i) {
        int r, c;
        cin >> r >> c;
        if ((r + c) % 2 == 0) {
            white++;
        } else {
            black++;
        }
    }

    cout << K - max(white, black) << endl;

    return 0;
}