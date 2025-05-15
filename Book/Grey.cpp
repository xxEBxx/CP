#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n,pos,res=0;
        cin>>n>>pos;
        for(int i=0;i<n;i++){
            if (pos < (1<<i)){
                continue;
            }
            else if (  ((pos - (1<<i))/(1<<i+1)) %2 == 0){
                res += (1<<i);
            }
        }
        cout<<res<<endl;
    }
}