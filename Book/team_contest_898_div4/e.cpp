//WORKEDDDD
#include<bits/stdc++.h>

using namespace std;

long long  solve(vector<long long>& arr,long long x){
    sort(arr.begin(),arr.end());
    int n=arr.size();
    //cout<<n;
    //to get the height arr[i] with index i we need needed[i]
    //piece of water and we may add whats left;
    vector<long long> needed(n);
    needed[0]=0;
    for(int i=1;i<n;i++){
        needed[i]=needed[i-1]+i*(arr[i]-arr[i-1]);
    }

    int start=0,end=n-1,mid;
    while(start <= end){
        mid=(start+end)/2;
        //cout<<"here is mid now "<<mid<<endl;
        if(needed[mid]==x){
            return arr[mid];
        }
        else if(needed[mid] > x){
            end=mid-1;
        }
        else{
            start=mid+1;
        }

    }
    while(needed[mid]>x && needed[mid-1]<x){
        mid--;
    }
    /*while(arr[mid]==arr[mid+1]){
        mid++;
    }*/
    long long res=arr[mid];
    //cout<<"mid: "<<mid<<endl;
    x-=needed[mid];
    //cout<<"x: "<<x<<endl;
    res+=x/(mid+1);
    return res;
}

int main(){
    int t;cin>>t;
    while(t--){
        long long n,x;
        cin>>n>>x;
        vector<long long> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<solve(arr,x)<<endl;
    }
}
/*
 * 1
2 1
1 1*/