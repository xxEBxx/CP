#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    int t;cin>>t;
    while(t--){
        int n,res=3;cin>>n;
        vector<int> arr(n+1);
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        for(int i=1;i<=n;i++){
            if(arr[arr[i]]==i){
                res=2;
                break;
            }
        }
        cout<<res<<endl;
    }
}