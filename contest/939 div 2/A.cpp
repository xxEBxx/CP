#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    int t;cin>>t;
    while(t--){
        int k,q;
        cin>>k>>q;
        //cout<<"here is k q"<<k<<" "<<q<<endl;
        set<int> to_kick;
        for(int i=0;i<k;i++) {
            int a;cin >> a;
            to_kick.insert(a);
        }
        for(int i=0;i<q;i++){
            int v;cin>>v;
            cout<<min(*to_kick.begin()-1,v)<<" ";
        }
        cout<<endl;
    }
}