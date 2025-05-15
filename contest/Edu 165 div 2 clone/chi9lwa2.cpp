#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<vector<int>> arr(n+1,vector<int> (1+n,0));
        vector<int> res(n+1,(1<<30)-1 );
        for(int i=1;i<1+n;i++){
            for(int j=1;j<1+n;j++){
                cin>>arr[i][j];
            }
        }
        for(int i=1;i<1+n;i++){
            for(int j=i+1;j<1+n;j++){
                res[i] &= arr[i][j];
                res[j] &= arr[i][j];
            }
        }
        bool real=true;
        for(int i=1;i<1+n;i++){
            for(int j=i+1;j<1+n;j++){
                if((res[i] | res[j]) != arr[i][j])real=false;
            }
        }
        if(real){
            cout<<"YES"<<endl;
            for(int i=1;i<=n;i++){
                cout<<res[i]<<" ";
            }
        }
        else{
            cout<<"NO";
        }
        cout<<endl;
    }
    return 0;
}