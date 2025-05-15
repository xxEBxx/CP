#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=2*1e5+7;

int main(){
    int t;cin>>t;
    while(t--){
        vector<int> have(maxn,0);
        int n;cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            have[arr[i]]++;
        }
        int count=0;
        for(int i=1;i<=n;i++){
            if(have[i]==2)count++;
        }
        cout<<count<<endl;

    }
}