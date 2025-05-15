#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,x;
    cin>>n>>x;
    //prefix sum,then difference from i+x to i
    vector<int> arr(n),asleep(n),ps(n),ps1(n),ps2(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cin>>asleep[i];
    }
    ps[0]=arr[0];
    //cout<<"ps : "<<ps[0]<<" ";
    for(int i=1;i<n;i++){
        ps[i]=ps[i-1]+arr[i];
        //cout<<ps[i]<<" ";
    }
    ps1[0]=ps[x-1];
    //cout<<endl<<"ps : "<<ps1[0]<<" ";
    for(int i=1;i<=n-x;i++){
        ps1[i]=ps[i+x-1]-ps[i-1];
        //from i to i+x all alive
        //cout<<ps1[i]<<" ";
    }
    //cout<<endl;
    //what we get if always awake is ps1
    ps2[0]=0;
    for(int i=0;i<x;i++){
        ps2[0]+=arr[i]*asleep[i];
    }
    //cout<<ps2[0]<<" ";
    for(int i=1;i<=n-x;i++){
        ps2[i]=ps2[i-1]-arr[i-1]*asleep[i-1]+asleep[x+i-1]*arr[i+x-1];
        //cout<<ps2[i]<<" ";
    }
    //cout<<endl;
    for(int i=0;i<=n-x;i++){
        ps[i]=ps1[i]-ps2[i];
        //the win of beginning with this index;
    }
    int max_index=0;
    for(int i=1;i<=n-x;i++){
        if(ps[i] > ps[max_index]){
            max_index=i;
        }
    }
    for(int i=max_index;i<max_index+x;i++){
        asleep[i]=1;
    }
    int res=0;
    for(int i=0;i<n;i++){
        if(asleep[i]==1)res+=arr[i];
    }
    cout<<res;
    return 0;
}