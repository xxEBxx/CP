#include<bits/stdc++.h>

using namespace std;
int main(){
    string N,M,res="";
    cin>>N>>M;
    int n=N.size() , m =M.size();
    if (n<m){
        int k=m-n-1;
        res+="0.";
        while (k--){
            res+="0";
        }
        res+=N;
    }
    else{
        for (int i=0;i<n-m+1;i++){
            //cout<<i;
            res+=N[i];
        }
        res+='.';
        for(int i=n-m+1;i<n;i++){
            //cout<<i;
            res+=N[i];
        }
    }
    int len = res.size()-1;
    while(res[len]=='0'){
        res.pop_back();
        len--;
    }
    if(res[len]=='.'){
        res.pop_back();
    }
    cout<<res<<endl;
}