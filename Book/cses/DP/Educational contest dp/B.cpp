#include<bits/stdc++.h>

using namespace std;
vector<bool> av(26);
int main(){
    int n,k;
    cin>>n>>k;
    string s;cin>>s;
    for(int i=0;i<k;i++){
        char c;cin>>c;
        av[c-'a']=true;
    }
    vector<int> a(n);
    for(int i=0;i<n;i++){
        if(av[s[i]-'a'])a[i]=1;
        else a[i]=0;
    }
    vector<int> dp(n+1);
    dp[0]=0;
    int res=0;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            dp[i+1]=0;
        }
        else{
            dp[i+1]=dp[i]+1;
        }
        res+=dp[i+1];
    }

    cout<<res;
}