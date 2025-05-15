#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
    int t;cin>>t;
    while(t--){
        ll n,x;cin>>n>>x;
        vector<int> arr(n);
        ll tot=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            tot+=arr[i];
        }
        if(tot <= x){
            cout<<n<<endl;
            continue;
        }
            ll h1=(1+x)/2,h2=x/2;
            for(int i=0;i<n;i++){
                if(arr[i] <= h1){
                    h1-=arr[i];
                    arr[i]=0;
                }
                else{
                    break;
                }
            }
            for(int i=(int)n-1;i>=0;i--){
                if(arr[i] <= h2 ){
                    h2-=arr[i];
                    arr[i]=0;
                }
                else{
                    break;
                }
            }
            int count=0;
            for(int i=0;i<n;i++){
                count += arr[i]==0;
            }
            cout<<count<<endl;

    }
}