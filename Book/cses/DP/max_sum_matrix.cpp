#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;cin>>n;
    vector<vector<int>> arr(n,vector<int> (n));
    int res= - 127*100*100 -2;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
            if(i>0) arr[i][j]+=arr[i-1][j];
            if(j>0) arr[i][j]+=arr[i][j-1];
            if(i>0 && j!=0) arr[i][j] -= arr[i-1][j-1];
            //cout<<arr[i][j]<<" ";
        }
        //cout<<endl;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=i;k<n;k++){
                for(int l=j;l<n;l++){
                    int subRect = arr[k][l];
                    if (i > 0) subRect -= arr[i - 1][l];
                    if (j > 0) subRect -= arr[k][j - 1];
                    if (i > 0 && j > 0) subRect += arr[i - 1][j - 1];
                    res = max(res, subRect);                }
            }
        }
    }
    cout<<res<<endl;
}

