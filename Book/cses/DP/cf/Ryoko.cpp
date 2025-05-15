#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
    int x,n;cin>>x>>n;
    if(n==1) { cout << 0;return 0; }
    vector<int> arr(n),pot(n);
    for(int &a:arr)cin>>a;
    //potential is 0 if elem between 2 and distance to closest if he is not
    pot[0]=abs(arr[0]-arr[1]);
    pot[n-1]=abs(arr[n-1]-arr[n-1]);
    for(int i=1;i<n-1;i++){
        int a=min(arr[i+1],arr[i-1]),b=max(arr[i+1],arr[i-1]);
        if(arr[i]<=b && arr[i]>=a){
            pot[i]=0;
        }
        else pot[i]=2*min(abs(arr[i]-b),abs(arr[i]-a));
    }
    //for(int k :pot){cout<<k<<" ";}cout <<endl;
    //int index = max(pot.begin(),pot.end())-pot.begin();
    int index=0;
    for(int i=1;i<n;i++){
        if(pot[index] < pot[i])index=i;
    }
    //index of best potential;
    //cout<<"here is index"<<index;
    if(index==0)arr[0]=arr[1];
    else arr[index]=arr[index-1];
    //for(int k:arr)cout<<k<<" ";cout<<endl;
    ll res=0;
    for(int i=0;i<n-1;i++){
        res+=abs(arr[i+1]-arr[i]);
    }
    cout<<res<<endl;
}