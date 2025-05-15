//https://codeforces.com/problemset/problem/489/B
#include<bits/stdc++.h>

using namespace std;
int main(){
    int n;cin>>n;
    vector<int> boys(n);
    for(int &i:boys)cin>>i;
    int m;cin>>m;
    vector<int> girls(m);
    for(int &i:girls)cin>>i;
    sort(boys.begin(),boys.end());
    sort(girls.begin(),girls.end());
    int i=0,j=0,count=0;
    while(i<n && j<m){
        if(abs(boys[i]-girls[j]) < 2){
            i++;j++;count++;
        }
        else if (boys[i] > girls[j]){
            j++;
        }
        else i++;
    }
    cout<<count;
}
