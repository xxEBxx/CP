#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        if(n==1 && m==1){
            cout<<"YES"<<endl;
            continue;
        }
        if(n==1){
            if(arr[0][0]==arr[0][m-1]){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
            continue;
        }
        if(m==1){
            if(arr[n-1][0]==arr[0][0]){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
            continue;
        }
        bool doable=false;

        if(arr[0][0]==arr[n-1][m-1] || arr[0][m-1]==arr[n-1][0]){
            cout<<"YES"<<endl;
            continue;
        }
        unordered_map<int ,int> ma;

        for(int i=0;i<n;i++){
            //for j=0;
            if(arr[i][0]=='B'){
                ma[4]=1;
                break;
            }
        }
        for(int i=0;i<n;i++){
            //for j=0;
            if(arr[i][0]=='W'){
                ma[4]+=2;
                break;
            }
        }

        for(int i=0;i<m;i++){
            //for i=n-1;
            if(arr[n-1][i]=='B'){
                ma[3]=1;
                break;
            }
        }
        for(int i=0;i<m;i++){
            //for i=n-1;
            if(arr[n-1][i]=='W'){
                ma[3]+=2;
                break;
            }
        }

        for(int i=0;i<n;i++){
            //for i=m-1;
            if(arr[i][m-1]=='B'){
                ma[2]+=1;
                break;
            }
        }
        for(int i=0;i<n;i++){
            //for i=m-1;
            if(arr[i][m-1]=='W'){
                ma[2]+=2;
                break;
            }
        }

        for(int i=0;i<m;i++){
            //for i=n-1;
            if(arr[0][i]=='B'){
                ma[1]+=1;
                break;
            }
        }
        for(int i=0;i<m;i++){
            //for i=n-1;
            if(arr[0][i]=='W'){
                ma[1]+=2;
                break;
            }
        }
        //cout<<"ma"<<ma[1]<<" "<<ma[2]<<" "<<ma[3]<<" "<<ma[4]<<" ";

        if(arr[0][0] && ma[4]==3 && ma[1]==3){
            doable=true;
            //cout<<0<<0<<endl;
        }
        else if(arr[n-1][0] && ma[4]==3 && ma[3]==3){
            doable=true;
            //cout<<"n-1 0"<<endl;
        }
        else if(arr[0][m-1] && ma[1]==3 && ma[2]==3){
            doable=true;
            //cout<<"0 m-1"<<endl;
        }
        else if(arr[n-1][m-1] && ma[2]==3 && ma[3]==3){
            doable=true;
            //cout<<"n-1 m-1"<<endl;
        }

        if(doable){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}