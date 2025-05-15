#include<bits/stdc++.h>

using namespace std;

long long solve(vector<long long> arr){
    long long sum_end_here=0,max_sum=INT_MIN,n=arr.size();
    for(int i=0;i<n;i++){
        sum_end_here+=arr[i];
        if(sum_end_here > max_sum){
            max_sum=sum_end_here;
        }
        if(sum_end_here<0){
            sum_end_here=0;
        }

    }
    return max_sum;
}

int main(){
    int n;cin>>n;
    vector<long long> v(n),ps(n+1);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    cout<<solve(v);
}