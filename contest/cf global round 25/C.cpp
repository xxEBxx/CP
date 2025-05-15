#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef long long ll;

int main(){
    int t;cin>>t;
    while(t--){
        int n,m,x;
        cin>>n>>m>>x;//m is max and x is the goal
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        vector<int> buy(n,0);
        priority_queue<ii,vector<ii>,greater<>> heap;
        //keep track of lowest price and its index
        for(int i=0;i<n;i++){
            heap.emplace(v[i],i);
        }
        while(x >= m){
            ii elem= heap.top();
            heap.pop();
            buy[elem.second]=m;
            x-=m;
        }
        if(x!=0){
            ii elem = heap.top();
            heap.pop();
            buy[elem.second] = x;
        }
        //we know how much we gonna buy from each index
        /*for(int k:buy){
            cout<<k<<" ";
        }
        cout<<endl;*/
        ll res=0,bought=0;
        for(int i=0;i<n;i++){
            res+=buy[i]*(bought+v[i]);
            bought+=buy[i];
        }
        cout<<res<<endl;
    }

}