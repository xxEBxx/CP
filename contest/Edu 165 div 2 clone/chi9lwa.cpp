

#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        int count =0;
        for(int i=0;i<n-1;i++) {
            count += arr[i] / arr[i + 1];

        }
        cout<<count<<endl;
    }
    return 0;
}