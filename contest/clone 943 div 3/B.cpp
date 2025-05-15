#include<bits/stdc++.h>


using namespace std;
const int maxn=1e6+7;
typedef long long ll;


int main(){
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        string a,b;cin>>a>>b;
        int i=0,j=0;
        while(i<n && j<k){
            if(a[i]==b[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        cout<<i<<endl;
    }
    return 0;
}
