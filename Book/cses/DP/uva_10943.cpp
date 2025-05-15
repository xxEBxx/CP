#include<bits/stdc++.h>

using namespace std;
const int maxn=102;
typedef long long ll;
vector<vector<int>> arr(maxn,vector<int> (maxn,-1));
int main(){
    for(int i=1;i<maxn;i++){
        arr[0][i]=1;
        arr[i][1]=1;
        arr[i][2]=i+1;
    }
    for(int i=1;i<maxn;i++){
           for(int j=2;j<maxn;j++){
               arr[i][j]=(arr[i-1][j]+arr[i][j-1])%(int)1e6;
           }
    }
    for(int i=0;i<=100;i++){
        for(int j=0;j<5;j++){
            //cout<<arr[i][j]<<" ";
        }
        //cout<<endl;
    }
    while(true){
        int n,k;cin>>n>>k;
        if(n==0 && k==0)break;
        cout<<arr[n][k]<<endl;
    }
    return 0;
}