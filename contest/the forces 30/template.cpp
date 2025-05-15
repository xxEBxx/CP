#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        cout<<n/6 + (n%6!=0) <<" "<<n/4+(n%4!=0)<<endl;
    }
    return 0;
}