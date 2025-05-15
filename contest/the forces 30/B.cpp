#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n,a,b,count1=0,count0=0;cin>>n>>a>>b;
        string s;cin>>s;
        for(int i=0;i<n;i++){
            if(s[i]=='0')count0++;
            else count1++;
        }
        if(count1==0 || count0==0){
            cout<<0<<endl;
            continue;
        }
        int res1,res2;
        //remove the ones
        if(a*2 < b){
            res1=a*count1;
        }
        else{
            res1=b*(count1/2)+ min(a,2*b) * (count1 & 1);
        }
        //remove the 0's
        res2=min(a,b) * count0;
        //cout<<count0<<a<<b;
        cout<<min(res1,res2)<<endl;
    }
    return 0;
}