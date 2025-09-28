#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin >> arr[i];
        sort(arr.begin(),arr.end());
        vector<long long> un;
        un.push_back(arr[0]);
        for(int i=1;i<n;i++) {
            if(arr[i] != arr[i-1])
                un.push_back(arr[i]);
        }
        long long res = n - un.size();
        long long out = 1e16;
        //ll count un
        for(int i=un.size()-1;i>=0;i--) {
            long long cost = un[i] - (i+1);
            cost += (un.size() - i-1);
            out = min(out,cost);
        }
        cout << min((long long)(n+1),(out+res)) << endl;
    }

    return 0;
}