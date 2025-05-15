#include<bits/stdc++.h>

using namespace std;
const int maxn=1e5+7;
typedef long long ll;

int main(){
    int n=7;
    vector<int> parent={-1,0,0,1,1,2,2};
    int logn=17;
    vector<vector<int>> up(maxn,vector<int> (logn,0));
    for(int i=1;i<n;i++){
        up[i][0]=parent[i];
    }
    for(int j=1;j<logn;j++){
        for(int i=1;i<n;i++){
            up[i][j]=up[up[i][j-1]][j-1];
        }
    }
    int node=5,k=2,l=0;
    while(k>0){
        if(k & 1){
            node=up[node][l];
        }
        l++;
        k/=2;
    }
    cout<<node;
}
