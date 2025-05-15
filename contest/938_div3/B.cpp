#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int n,c,d;
string solve(multiset<int>&  arr,int min_val){
    multiset<int> nv;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            nv.insert(min_val+i*c+j*d);
        }
    }
    if(nv==arr){
        return "YES";
    }
    return "NO";
    return "YES";
}

int main(){
    int t;cin>>t;
    while(t--){
        cin>>n>>c>>d;
        multiset<int> arr;
        int min_val=1e9+2;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int val;cin>>val;
                arr.insert(val);
                if(val<min_val)min_val=val;
            }
        }
        cout<<solve(arr,min_val)<<endl;
    }
}