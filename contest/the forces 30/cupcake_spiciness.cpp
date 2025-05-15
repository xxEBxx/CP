#include<bits/stdc++.h>

using namespace std ;
typedef long long ll;

int main(){
    int n,a,b;cin>>n>>a>>b;
    vector<int> arr(n);
    for(int &i:arr)cin>>i;
    sort(arr.begin(),arr.end());
    if(a<0){
        reverse(arr.begin(),arr.end());
    }
    ll res=0;
    for(int i=0;i<n;i++){
        res+=(i+1)*(a*arr[i]+b);
    }
    cout<<res<<endl;
}