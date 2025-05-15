#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long smallestImpossibleSum(vector<long long>& arr) {
    sort(arr.begin(), arr.end());

    long long result = 1;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > result) {
            break;
        }
        result += arr[i];
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    cout << smallestImpossibleSum(v) << endl;

    return 0;
}
