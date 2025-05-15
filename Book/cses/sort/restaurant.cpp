#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,value;cin>>n;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        cin>>value;
        v.push_back(make_pair(value,1));
        cin>>value;
        v.push_back(make_pair(value,-1));
    }
    sort(v.begin(),v.end());
    int max_value=0,actual=0;
    for(auto pair: v){
        actual+=pair.second;
        max_value=max(max_value,actual);
    }
    cout<<max_value;
}