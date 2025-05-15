#include<bits/stdc++.h>

using namespace std;

int main(){
    int k,n;cin>>k>>n;
    if(n < k || k*9 <n ){
        cout<<"-1 -1"<<endl;
        return 0;
    }
    vector<vector<int>> dpmin(n+1,vector<int> (k+1,-1));
    vector<vector<int>> dpmax(n+1,vector<int> (k+1,-1));

    //s is the number and m is the len
    //given m we should compute min from m to 9*m
    for(int i=1;i<=n;i++){
        dpmin[i][1]=i;
        dpmax[i][1]=i;
    }
    for(int i=1;i<=k;i++){
        for(int j=i;j<=9*i;j++){
            dpmin[i][j]=
        }
    }
}