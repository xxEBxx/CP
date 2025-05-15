#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll NEG_INF = -1e18;

int n;
vector<int> givenA, givenB; // given arrays (length n-1)
int missing_a, missing_b;

// dp[i][usedA][usedB] stores maximum achievable cost from state (i,usedA,usedB).
vector<vector<vector<ll>>> dp;
// choice[i][usedA][usedB] stores which action was chosen (0,1,2,3) at that state.
vector<vector<vector<int>>> choiceRec;

ll solve(int i, int usedA, int usedB) {
    if(i == n) {
        // Only valid if both missing elements have been inserted.
        return (usedA == 1 && usedB == 1) ? 0 : NEG_INF;
    }
    ll &res = dp[i][usedA][usedB];
    if(res != NEG_INF) return res;
    int posA = i - usedA; // pointer into givenA
    int posB = i - usedB; // pointer into givenB
    ll best = NEG_INF;
    int bestAct = -1;

    // Option 0: Use both given elements (if available)
    if(posA < n-1 && posB < n-1) {
        ll candidate = abs(givenA[posA] - givenB[posB]) + solve(i+1, usedA, usedB);
        if(candidate > best) {
            best = candidate;
            bestAct = 0;
        }
    }
    // Option 1: Insert missing_a in permutation A (if not already used)
    if(usedA == 0 && posB < n-1) {
        ll candidate = abs(missing_a - givenB[posB]) + solve(i+1, 1, usedB);
        if(candidate > best) {
            best = candidate;
            bestAct = 1;
        }
    }
    // Option 2: Insert missing_b in permutation B (if not already used)
    if(usedB == 0 && posA < n-1) {
        ll candidate = abs(givenA[posA] - missing_b) + solve(i+1, usedA, 1);
        if(candidate > best) {
            best = candidate;
            bestAct = 2;
        }
    }
    // Option 3: Insert both missing elements simultaneously (if neither used)
    if(usedA == 0 && usedB == 0) {
        ll candidate = abs(missing_a - missing_b) + solve(i+1, 1, 1);
        if(candidate > best) {
            best = candidate;
            bestAct = 3;
        }
    }
    dp[i][usedA][usedB] = best;
    choiceRec[i][usedA][usedB] = bestAct;
    return best;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    givenA.resize(n-1);
    givenB.resize(n-1);
    ll total = (ll)n*(n+1)/2;
    ll sumA = 0, sumB = 0;
    for (int i = 0; i < n-1; i++){
        cin >> givenA[i];
        sumA += givenA[i];
    }
    for (int i = 0; i < n-1; i++){
        cin >> givenB[i];
        sumB += givenB[i];
    }
    missing_a = total - sumA;
    missing_b = total - sumB;

    // Initialize dp and choiceRec arrays with dimensions (n+1) x 2 x 2.
    dp.assign(n+1, vector<vector<ll>>(2, vector<ll>(2, NEG_INF)));
    choiceRec.assign(n+1, vector<vector<int>>(2, vector<int>(2, -1)));

    ll ans = solve(0, 0, 0);
    cout << ans << "\n";

    // Reconstruction: build the restored permutations from decisions.
    vector<int> restoredA(n, 0), restoredB(n, 0);
    int i = 0, usedA = 0, usedB = 0;
    int ptrA = 0, ptrB = 0;
    for (int pos = 0; pos < n; pos++){
        int act = choiceRec[i][usedA][usedB];
        if(act == 0) {
            // Option 0: use both given elements.
            restoredA[pos] = givenA[ptrA];
            restoredB[pos] = givenB[ptrB];
            ptrA++; ptrB++;
        } else if(act == 1) {
            // Option 1: insert missing_a in A.
            restoredA[pos] = missing_a;
            restoredB[pos] = givenB[ptrB];
            ptrB++;
            usedA = 1;
        } else if(act == 2) {
            // Option 2: insert missing_b in B.
            restoredA[pos] = givenA[ptrA];
            restoredB[pos] = missing_b;
            ptrA++;
            usedB = 1;
        } else if(act == 3) {
            // Option 3: insert both missing simultaneously.
            restoredA[pos] = missing_a;
            restoredB[pos] = missing_b;
            usedA = usedB = 1;
        }
        i++;
    }

    // Output the restored permutations.
    for (int x : restoredA) cout << x << " ";
    cout << "\n";
    for (int x : restoredB) cout << x << " ";
    cout << "\n";

    return 0;
}