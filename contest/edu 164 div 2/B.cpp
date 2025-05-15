#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define all(v) v.begin(),v.end()

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> v(n);
        for(int &a:v)cin>>a;
        bool imp=true;
        for(int i=0;i<n;i++){
            if(v[0]!=v[i]){
                imp=false;
                break;
            }
        }
        if(imp) {
            cout << -1 << endl;
            continue;
        }
        int last_problem,res;
        for(int i=1;i<n;i++){
            if(v[i]!=v[0]){
                res=i;
                last_problem=i;
                break;
            }
        }
        for(int i=last_problem+1;i<n;i++){
            if(v[i]!=v[0]){
                res=min(res,i-last_problem-1);
                last_problem=i;
            }
        }
        cout<<min(res,n-last_problem-1)<<endl;
    }
    return 0;
}
/*
 1
18
1 1 1 1 2 1 1 1 1  2 1 1 1 1 2 1 1 1
 */