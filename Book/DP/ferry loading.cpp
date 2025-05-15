#include <stdio.h>
#include <string.h>

char dp[205][10005], pre[205][10005];

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int length, n, A[2005], sum[2005] = {};
        int i, j;
        scanf("%d", &length);
        length *= 100;

        n = 1;
        while (scanf("%d", &A[n]), A[n]) {
            sum[n] = sum[n-1] + A[n];
            n++;
        }

        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1; // Initially, 0 length at both sides is feasible
        n--;

        int mx_car = 0, mx_len = 0;
        for (i = 1; i <= n; i++) {
            for (j = 0; j <= length; j++) {
                if (j - A[i] >= 0 && dp[i-1][j - A[i]]) { // Left side
                    dp[i][j] = 1;
                    pre[i][j] = 0; // Mark as left
                }
                if (sum[i] - j <= length && dp[i-1][j]) { // Right side
                    dp[i][j] = 1;
                    pre[i][j] = 1; // Mark as right
                }
                if (dp[i][j]) {
                    mx_car = i;
                    mx_len = j;
                }
            }
            if (mx_car != i) break; // If no more cars can be loaded
        }

        printf("%d\n", mx_car);

        int where[205];
        i = mx_car;
        j = mx_len;
        while (i) {
            where[i] = pre[i][j];
            if (!pre[i][j]) j -= A[i];
            i--;
        }

        for (i = 1; i <= mx_car; i++)
            puts(where[i] ? "starboard" : "port");

        if (t) puts(""); // Print an empty line between test cases
    }

    return 0;
}
