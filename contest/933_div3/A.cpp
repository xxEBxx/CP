#include<bits/stdc++.h>

using namespace std;

string solve(vector<int>& arr ){
    for(int i=0;i<arr.size()-2;i++){
        int k=arr[i];
        arr[i]=0;
        if(arr[i+2]>=k && arr[i+1]>=2*k){
            arr[i+2]-=k;
            arr[i+1]-=2*k;
        }
        else{
            return "NO";
        }
    }
    for(int i=0;i<arr.size();i++){
        if(arr[i]!=0)return "NO";
    }
    return "YES";
}

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<solve(arr)<<endl;
    }
}