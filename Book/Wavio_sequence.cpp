#include<bits/stdc++.h>

using namespace std;

const int maxn = 10000; // Assuming max size of the array

// Define dp_inc and dp_dec arrays outside the function
int dp_inc[maxn];
int dp_dec[maxn];

void lis_nlogn(vector<int>& v) {
    int n = v.size();
    vector<int> tail(n, 0); // tail[i] represents the smallest ending element of LIS of length i+1
    int len = 1; // length of LIS

    tail[0] = v[0];
    dp_inc[0] = 1;

    for (int i = 1; i < n; i++) {
        if (v[i] < tail[0]) {
            // New smallest value
            tail[0] = v[i];
            dp_inc[i] = 1;
        } else if (v[i] > tail[len - 1]) {
            // v[i] extends largest subsequence
            tail[len++] = v[i];
            dp_inc[i] = len;
        } else {
            // v[i] will become a candidate for future LIS
            int pos = lower_bound(tail.begin(), tail.begin() + len, v[i]) - tail.begin();
            tail[pos] = v[i];
            dp_inc[i] = pos + 1;
        }
    }
}

void lds_nlogn(vector<int>& v) {
    reverse(v.begin(), v.end());
    lis_nlogn(v); // Reversing the array and computing LIS gives LDS

    // Copy the computed LDS to dp_dec array
    for (int i = 0; i < v.size(); i++) {
        dp_dec[i] = dp_inc[i];
    }
    reverse(dp_dec, dp_dec + v.size()); // Reversing the LIS array to get LDS
}

int main() {
    int n,max_value=1,value;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>value;
        v[i]=value;
    }
    memset(dp_inc,-1, size(dp_inc));
    memset(dp_dec,-1, size(dp_dec));

    lis_nlogn(v); // Compute LIS
    lds_nlogn(v); // Compute LDS

    for(int i=0;i<n;i++){
        int temp= min(dp_inc[i],dp_dec[i]);
        if (max_value < temp){
            max_value=temp;
        }
    };
    cout<<max_value*2-1<<endl;
    return 0;
}
