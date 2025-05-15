#include<bits/stdc++.h>

using namespace std;

int solve(vector<int> arr){
    int n=arr.size(),j=0,res=0;
    set<int> s;
    for(int i=0;i<n;i++){
        while(s.count(arr[i])){
            s.erase(arr[j]);
            j++;
        }
        s.insert(arr[i]);
        res=max(res,(int)s.size());
    }
    return res;
}

int main(){
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<solve(arr);
}