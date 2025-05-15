#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int main(){
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        vector<string> arr(n);
        vector<int> zeros(n,0);
        for(string &a:arr)cin>>a;
        int nz=0;
        for(int i=0;i<n;i++){
            int j=arr[i].size()-1;
            //cout<<"size"<<j+1;
            while(j>=0 && arr[i][j] == '0'){
                j--;
            }
            nz += j+1;
            zeros[i]=arr[i].size()-j-1;
            //cout<<nz<<" ";
        }
        sort(zeros.begin(),zeros.end());
        reverse(zeros.begin(),zeros.end());
        for(int i=0;i<n;i++){
            //cout<<zeros[i];
            if(i&1){
                nz += zeros[i];
            }
        }
        if(nz > m){
            cout<<"Sasha"<<endl;
        }
        else{
            cout<<"Anna"<<endl;
        }
    }
}