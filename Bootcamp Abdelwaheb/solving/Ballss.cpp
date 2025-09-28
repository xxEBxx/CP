
#include <bits/stdc++.h>


using namespace std;

const int N = 5e5 + 10;

int mem[51][1001];
int B = 50, H = 1000;

void solve() {
    for (int b = 1; b <= B; ++b) {
        int f = 1;
        for (int h = 0; h <= H; ++h) {
            int &ret = mem[b][h];
            if (!h or b == 1) {
                ret = h;
                continue;
            }
            ret = 1e9;
            for (; f <= h; ++f){
                if ( mem[b][f - 1] > mem[b - 1][h - f]) {
                    ret = mem[b][f-1] + 1;
                    break;
                }
            }
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    solve();
    while (t--) {
        int tc;
        scanf("%d%d%d", &tc, &B, &H);
        printf("%d %d\n", tc, mem[B][H]);
    }
    return 0;
}
