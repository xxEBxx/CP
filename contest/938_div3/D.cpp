#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

string solve(vector<int>& arr){
    for(int i=1;i<arr.size();i++){
        if(arr[i] >= arr[i-1]){
            return "YES";
        }
    }
    return "NO";
}

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        cout<<solve(v)<<endl;
    }
}