#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;


int main(){
    int t;cin>>t;
    while(t--){
        int n,k=0;string s;
        bool adj=false;
        cin>>n>>s;

        for(int i=0;i<n;i++){
            if(s[i]=='1') {
                k++;
                if (i < n - 1 && s[i + 1] == '1')adj = true;
            }
        }
        if(k==2) {
            if(!adj)cout << "YES";
            else cout<<"NO";
        }
        else if(k%2==0)cout<<"YES";
        else{
            cout<<"NO";
        }
        cout<<endl;
    }
return 0;
}