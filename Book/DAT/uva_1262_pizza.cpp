#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        string s;
        cin>>s;
        map<char,int> map1;
        int n=s.size();
        for(int i=0;i<n;i++){
            map1[s[i]]++;
            //cout<<"map de "<<s[i]<<"est"<<map1[s[i]]<<endl;
        }
        int count=min(map1['M'],map1['A']/3);
        //cout<<count;
        count=min(count,map1['R']/2);
        count=min(count,map1['G']);
        count=min(count,map1['T']);
        count=min(count,map1['I']);
        cout<<count<<endl;
    }
}