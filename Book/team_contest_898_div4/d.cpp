#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        cin.ignore();
        string s;
        getline(cin,s);
        //cout<<s;
        int i=0,count=0;
        while(i<n){

            if(s[i]=='B'){
                if(i+k>=n){
                    count++;
                    break;
                }
                for(int j=0;j<k;j++){
                    s[i+j]='W';
                }
                count++;
            }
            i++;
        }

    cout<<count<<endl;
    }
}