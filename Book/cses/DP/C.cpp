#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        set<int> arr;
        for(int i=0;i<n;i++){
            int v;cin>>v;
            arr.insert(v);
        }
        vector<int> v;
        for(auto it:arr){
            v.push_back(it);
        }
        vector<int> v1(v.size()),ans(v.size());
        v1[0]=v[0];
        for(int i=1;i<v.size();i++){
            v1[i]=v[i]-v[i-1];
        }
        ans[v.size()-1]=0;
        for(int i=v.size()-2;i>=0;i--){
            //0 for alice and 1 for Bob;
            if(v1[i]==1){
                ans[i]=1-ans[i+1];
            }
            else{
                ans[i]=0;
            }
        }
        //cout<<count;
        if( ans[0]==0 )cout<<"Alice"<<endl;//pair
        else cout<<"Bob"<<endl;

    }
    return 0;
}