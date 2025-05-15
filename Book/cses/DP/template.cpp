#include<bits/stdc++.h>

using namespace std;

int solve(unordered_map<int,int> ma,int m,int n){
    for(auto elem:ma){
        if(elem.second >= m){
            return m-1;
        }
    }
    return n;
}

int main(){
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        unordered_map<int,int> ma;
        for(int i=0;i<n;i++){
            int val;cin>>val;
            ma[val]++;
        }
        cout<<solve(ma,m,n)<<endl;

    }
}