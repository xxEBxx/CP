#include<bits/stdc++.h>


using namespace std;
const int maxn=1e6+7;
typedef long long ll;


int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> arr(n);
        //arr is all teh x's
        for(int i=1;i<n;i++)cin>>arr[i];
        int a=997;
        cout<<a<<" ";
        for(int i=1;i<n;i++){
            a+=arr[i];
            cout<<a<<" ";
        }
        cout<<endl;
    }
    return 0;

}
