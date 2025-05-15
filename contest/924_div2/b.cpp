#include<iostream>
#include<algorithm>
#include<vector>
#include <unordered_map>
#include<set>

using namespace std;

int solve(vector<int>& arr) {
    int k = arr.size(); 

    if (arr[k - 1] - arr[0] < k) {
        unordered_map<int,int> once;
        int count = 0;
        for (int i = 0; i < k; i++) {
            if (once[arr[i]] == 0) {
                count++;
                once[arr[i]]=1;
            }
        }
        return count;
    }
    return max(solve( vector<int>(arr.begin() + 1, arr.end())),
               solve( vector<int>(arr.begin(), arr.end() - 1));
}

int main() {
    int t;
    cin >> t;
    for (int kk = 0; kk < t; kk++) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(),arr.end());

        set<int> unique_elements(arr.begin(), arr.end());
        vector<int> unique_vector(unique_elements.begin(), unique_elements.end());

        cout << solve(unique_vector) << endl; 
    }
    return 0;
}
