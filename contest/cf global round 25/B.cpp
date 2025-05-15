#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
    ll t;cin>>t;
    while(t--){
        int n,x,count=0;cin>>n>>x;
        vector<ll> arr(n+1);
        for(int  i=1;i<n+1;i++){
            cin>>arr[i];
        }
        for(int i=1;i<1+n;i++){
            if(i != x){
                if (arr[i] < arr[x]) {
                    count++;
                } else {
                    break;
                }
            }
        }
        int indexM=x;
        for(int i=1;i<x;i++){
            //cout<<"hi";
            if(arr[i] > arr[x]){
                indexM=i;
                break;
            }
        }
        int count2;
        if(indexM!=1 && indexM < x){
            count2=1;
        }
        else{
            count2=0;
        }
        for(int i=indexM+1;i<x;i++){
            //cout<<"blocked";
            if(arr[i] < arr[x]){
                count2++;
            }
            else{
                break;
            }
        }
        if(count2>0)count--;
        cout<<max(count,count2)<<endl;
    }

}