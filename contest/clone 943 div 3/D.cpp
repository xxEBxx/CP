#include<bits/stdc++.h>


using namespace std;
const int maxn=1e6+7;
typedef long long ll;

//MATNSACJ LONG LONG
int main(){
    int t;cin>>t;
    while(t--){
        int n,k,ps,pb;cin>>n>>k>>pb>>ps;
        vector<int> jumps(n+1),reward(n+1);
        for(int i=1;i<n+1;i++){
            cin>>jumps[i];
        }
        int max_index=0;reward[0]=-1;
        for(int i=1;i<n+1;i++){
            cin>>reward[i];
            if(reward[i]>reward[max_index])max_index=i;
        }
        vector<int> dp(n+1,0);
        //this array should store from what k should we bw moving
        //to the next element that is bigger than us
        if(dp[])

    }


}
