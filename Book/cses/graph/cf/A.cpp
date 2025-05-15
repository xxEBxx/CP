//link : https://codeforces.com/problemset/problem/500/A

#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k;cin>>n>>k;
    vector<int> v(n);
    for(int i=1;i<n;i++){
        cin>>v[i];
        //cout<<v[i]<<" ";
    }
    int curr=1;
    while(curr < k ){
        //cout<<"curr "<<curr<<endl;
        curr+=v[curr];
    }
    if(curr==k)cout<<"YES";
    else cout<<"NO";
    return 0;
}