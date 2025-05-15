#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n;
    vector<float> blue(n),orange(n);
    for(int i=0;i<n;i++){
        cin>>blue[i];
    }
    for(int i=0;i<n;i++){
        cin>>orange[i];
    }
    cin>>m;
    for(int kk=0;kk<m;kk++){
        int val;
        cin>>val;
        val-=2;
        long double res=0.0;
        int end,start;
        if(val<=n){
            start=0;
            end=val;
        }
        else{
            start=val-n+1;
            end=n-1;
        }
        for(int i=start;i<=end;i++){
            res+=blue[i]*orange[val-i];
        }
        cout<<res<<endl;
    }
}