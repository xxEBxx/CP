#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,n;cin>>t;
    while(t--){
        cin>>n;
        int k;cin>>k;
        map<int,priority_queue<int,vector<int>,greater<int>>,greater<int> > m;
        //this will map the last modulo to all indexes that have this element
        for(int i=0;i<n;i++){
            int value;cin>>value;
            int ins=value%k;
            if(ins==0)ins=k;
            m[ins].push(i);
        }
        for(auto& element:m){
            //elemenet->second is a set
            int card=element.second.size();
            for(int i=0;i<card;i++){
                cout<<1+element.second.top()<<" ";
                element.second.pop();
            }
        }
        cout<<endl;
    }
}