#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    int t;cin>>t;
    while(t--){
        string s;cin>>s;
        ll count_ones=0,count=0;
        for(char c:s){
            if(c=='1'){
                count_ones++;
            }
            else{
                if(count_ones != 0){
                    count+= 1+count_ones;
                }
            }
        }
        cout<<count<<endl;
    }
    return 0;
}