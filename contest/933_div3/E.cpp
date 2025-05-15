#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
    int t;cin>>t;
    while(t--){
        int n,m,x,d;
        cin>>n>>m>>x>>d;
        vector<vector<int>> arr(n+1,vector<int>(m+1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }

        vector<ll> dp(n+1,0);
        for(int i=0;i<n;i++){
            //we find best way for each row;
            multiset<ll> previous;
            //this map will store values and there occurences ,also the first one will be the smallest
            vector<ll> one_bridge(m+1,0);
            one_bridge[0]=1;
            previous.insert(1);
            for(int j=1;j<=d+1 && j<m ;j++) {
                one_bridge[j]=arr[i][j]+2;
                previous.insert(one_bridge[j]);
                //cout<<"here is one_bridge of "<<j<<" "<<one_bridge[j]<<endl;
            }
            for(int j=d+2;j<m;j++){
                //cout<<"here is all previous"<<previous.size()<<endl;

                //int val=1e9;
                //here we remove the element that can't be used no more
                auto it=previous.find(one_bridge[j-d-2]);
                previous.erase(it);

                one_bridge[j]= *previous.begin() + arr[i][j]+1;
                //cout<<"here is one_bridge of "<<j<<" "<<one_bridge[j]<<endl;
                previous.insert(one_bridge[j]);
            }
            dp[i]=one_bridge[m-1];
           //cout<<"here is dp of i"<<dp[i]<<" "<<i<<endl;
        }
        //cout<<"dp of "<<0<<" "<<dp[0]<<endl;
        for(int i=1;i<n;i++){
            dp[i]+=dp[i-1];
            //cout<<"dp of "<<i<<" "<<dp[i]<<endl;
        }
        ll res=dp[x-1];
        for(int i=x;i<n;i++){
            res=min(res,dp[i]-dp[i-x]);
        }
        cout<<res<<endl;
    }

}

/*
1
1 11 1 4
0 1 2 3 2 1 2 3 3 2 0

 */