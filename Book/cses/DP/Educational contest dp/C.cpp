#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
const int maxn =1003,inf =1e7+20;
vector<vector<int>> dp(maxn,vector<int> (8,inf) );

int main(){
    int n;cin>>n;
    dp[0][0]=0;
    for(int i=0;i<n;i++){
        int price;cin>>price;
        string s;cin>>s;
        int bitmask=0;
        for(char c:s){
            if(c=='A')bitmask+=1;
            else if(c=='B')bitmask+=2;
            else bitmask+=4;
        }
        //string then its price

        //THE PUSH
        for(int mask=0;mask<8;mask++){
            //NOT TAKING THE ELMENT IS STORED HERE
            dp[i+1][mask]=min(dp[i+1][mask],dp[i][mask]);
            //TAKING THE ELMENT IS STORED HERE
            dp[i+1][mask | bitmask]=min(dp[i+1][mask | bitmask],dp[i][mask]+price);
        }
        /*
        We use the push method :
         -not taking element will check this element and the one before with same mask
         you are at to 3rd element and you found a price in the to 2nd element you may consider it
         -taking an element will be between itself , and between not taking it till the index before +price to take it
         you just go to a i one time before that has surely been computed before (mask <= mask|bitmask)
         with price to merge it wivh is cost
         */
    }

    int ans=dp[n][7];
    if(ans > 1e7)cout<<-1;
    else cout<< ans;
    return 0;
}