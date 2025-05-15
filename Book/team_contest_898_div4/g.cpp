#include<bits/stdc++.h>

using namespace std;

int solve(string& a,int sum){
    if(a=="AB" || a=="BA") {

        return 1;
    }

}

int main(){
    int t;cin>>t;
    while(t--){
        string line;
        getline(cin,line);
        solve(line);
    }
}