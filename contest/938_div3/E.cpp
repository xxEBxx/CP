#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

bool solve(int n,int k,string s){
    vector<int> changes(n+1,0);
    for(int i=0;i<n;i++){
        if(i){
            changes[i]+=changes[i-1];
//i and i-1 share same changes except for the i-k element
//thats why later in the code , if i-k is changed we put -1 on i
//so that we know that the i-k did change the i-1 but not i
        }
        //based on what happenned before
        if(changes[i]&1){//changemenet impair
            if(s[i]=='0')s[i]='1';
            else s[i]='0';
        }

        if(s[i]=='0'){
            changes[i]++;//for next element to know the one before just changed
            if(i+k > n) return false;
            // problem in the last k elements(false)
            changes[i+k]--;
//this is to make sure the change this element will
// apply to i+k-1 doesnt affect the i+k th element
        }
    }
    return true;
}

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s;cin>>s;
        for(int k=n;k>=1;k--){
            if(solve(n,k,s)){
                cout<<k<<endl;
                break;
            }
        }

    }
    return 0;
}