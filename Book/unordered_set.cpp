#include<bits/stdc++.h>

using namespace std;

int main(){
    int kk=0;
    int t;cin>>t;
    while(t--){
        kk++;
        int n,m;
        cin>>n>>m;
        cin.ignore();
        vector<string> v(n),v2(m);
        string value;
        for(int i=0;i<n;i++){
            getline(cin,value);
            v[i]=value;
        }
        for(int i=0;i<m;i++){
            getline(cin,value);
            v2[i]=value;
        }
        unordered_set<string> s;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i]==" "){
                    s.insert(v2[j]);
                }
                else if(v2[j]==" "){
                    s.insert(v[i]);
                }
                else s.insert(v[i]+v2[j]);
            }
        }
        cout<<"Case "<<kk<<": "<<s.size()<<endl;
    }
}