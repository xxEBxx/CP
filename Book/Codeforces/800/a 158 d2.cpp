#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n,x;cin>>n>>x;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int max_value=max(arr[0],2*(x-arr[n-1]));
        for(int i=0;i<n-1;i++){
            max_value=max(arr[i+1]-arr[i],max_value);
        }
        cout<<max_value<<endl;
    }
}