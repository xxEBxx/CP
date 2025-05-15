#include<bits/stdc++.h>

using namespace std;

long long solve(vector<long long> arr){
    sort(arr.begin(),arr.end());
    int n=arr.size();
    int median=arr[n/2];
    long long sum=0;
    for(int i=0;i<n;i++){
        sum+=abs(median-arr[i]);
    }
    return sum;
}

int main(){
    int n;cin>>n;
    vector<long long> v(n),ps(n+1);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    cout<<solve(v);
}