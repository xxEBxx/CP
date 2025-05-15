#include<iostream>
using namespace std;
#define MAXN 100005
long dp[MAXN] ={0};

long indicatrice(long n){
    if (dp[n]!=0) return dp[n];
    for (int i =2 ; i<=n;i++){
        if (n%i == 0){
            return dp[n]= indicatrice(n/i) + n;
        }
    }
    
}

int main(){
    long n,sum=0;
    dp[1]=1;
    cin>>n;
    for (int i=1;i<n+1;i++){
        sum+=indicatrice(i);
    }
    cout<<sum % (int)((1e9) +7);
    return 0;
}