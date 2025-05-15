#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        if(k>1){
            cout<<"YES"<<endl;
        }
        else{
            vector<int> sorted=arr;
            sort(sorted.begin(),sorted.end());
            if(sorted==arr){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
    }
}