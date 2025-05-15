#include<bits/stdc++.h>
//CHROMATIC PAINTING
using namespace std;

int main(){
    int n;cin>>n;
    vector<int> v1(n),v2(n),res(n);
    for(int i=0;i<n;i++){
        cin>>v1[i];
    }
    for(int i=0;i<n;i++){
        cin>>v2[i];
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    reverse(v2.begin(),v2.end());
    for(int i=0;i<n;i++){
        res[i]=v1[i]+v2[i];
    }
    sort(res.begin(),res.end());
    cout<<res[n-1]-res[0];

}