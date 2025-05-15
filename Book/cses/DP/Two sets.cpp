#include<bits/stdc++.h>

using namespace std;
int maxn=502;
vector<int> dp(maxn,-1);
int main(){
    int n;cin>>n;
    if(n%4==1 || n%4==2){
        cout<<0;
    }
    else{
        cout<<n*(n+1)/(2*n);
    }
}