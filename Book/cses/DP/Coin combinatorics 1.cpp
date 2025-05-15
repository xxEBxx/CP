#include<bits/stdc++.h>

using namespace std;
const int mod=1e9+7;
vector<int> ways(1e6,0);

int main(){
    int n,k;cin>>n>>k;
    vector<int> pieces(n);
    for(int i=0;i<n;i++){
        cin>>pieces[i];
        ways[pieces[i]]=1;
    }
    ways[0]=0;
    for(int value=1;value<=k;value++){
        for(int i=0;i<n;i++){
            if(value-pieces[i]>=0){
                ways[value]=(ways[value]+ways[value-pieces[i]])%mod;
            }
        }
    }
    cout<<ways[k];
}