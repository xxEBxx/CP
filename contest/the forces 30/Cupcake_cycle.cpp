#include<bits/stdc++.h>

using namespace std;

int main(){
    int maxn=101;
    vector<vector<int>> arr(maxn,vector<int> (maxn,0));
    int n,r;cin>>n>>r;
    for(int ll=0;ll<n;ll++){
        int x,y,ri;
        cin>>ri>>x>>y;
        x+=50;y+=50;
        for(int i=x-ri;i<= x+ri;i++){
            for(int j=y-ri;j<=y+ri;j++){
                if((((i-50)*(i-50)+(j-50)*(j-50)) <= r*r) && ((i-x)*(i-x)+(j-y)*(j-y)) <=ri*ri ){
                    arr[i][j]=1;
                }
            }
        }
    }
    int count=0;
    for(int i=0;i<maxn;i++){
        for(int j=0;j<maxn;j++){
            count+=arr[i][j];
        }
    }
    cout<<count<<endl;
    return 0;
}