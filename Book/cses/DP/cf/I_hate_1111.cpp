//link: https://codeforces.com/problemset/problem/1526/B

#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int res=0;
        for(int i=0;i<n;i++){
            if(n-i*111 < 0)break;
            if((n-i*111)%11==0){
                res=1;
                break;
            }
        }
        if(res==1)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
