#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define v.begin(),v.end() all(v);
int main(){
    ll t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        vector<int> arr(n),win(n);
        for(int &le:arr)cin>>le;
        if(n==1){
            cout<<arr[0]<<endl;
            continue;}
        win[0]=max(0,arr[0]-arr[1]);
        win[n-1]=max(0,arr[n-1]-arr[n-2]);
        for(int i=1;i<n-1;i++){
            win[i]=max(0,max(arr[i]-arr[i-1],arr[i]-arr[i+1]));
        }
        //for(int le:win )cout<<le<<" ";
        for(int i=0;i<k;i++){
            int min_index=0;
            for(int j=1;j<n;j++){
                if(win[j] > win[min_index]){
                    min_index=j;
                }
            }
            if(min_index==0){
                arr[0]=arr[1];
                win[0]=0;
                win[min_index+1]=max(win[min_index+1],arr[min_index+1]-arr[min_index]);
            }
            else if(min_index==n-1){
                win[n-1]=0;
                arr[n-1]=arr[n-2];
                win[min_index-1]=max(win[min_index-1],arr[min_index-1]-arr[min_index]);
            }
            else{
                arr[min_index]=min(arr[min_index],min(arr[min_index+1],arr[min_index-1]));
                win[min_index]=0;
                win[min_index+1]=max(win[min_index+1],arr[min_index+1]-arr[min_index]);
                win[min_index-1]=max(win[min_index-1],arr[min_index-1]-arr[min_index]);
            }
            /*cout<<"transformed arround"<<min_index<<endl;
            for(int le:arr)cout<<le<<" ";
            cout<<endl;
            for(int le:win)cout<<le<<" ";
            cout<<endl;*/
        }
        int count =0;
        for(int le:arr)count+=le;
        cout<<count<<endl;
    }
}

