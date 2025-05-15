#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){

    int t;cin>>t;
    while(t--){
        string s;cin>>s;int n=s.size();
        int count1=0,count0=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1')count1++;
            else count0++;
        }
        int i;
        for(i=0;i<n;i++){
            if(s[i]=='1' && count0 > 0)count0--;
            else if(s[i]=='0' && count1 > 0)count1--;
            else break;
        }
        cout<< n - i<<endl;
    }
    return 0;
}
