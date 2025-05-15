#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

void show(int n){
    for(int i=1;i<=n;i++)cout<<i<<" ";
    cout<<endl;
}

int main(){
    int t;cin>>t;
    while(t--){
        int n,k=0;cin>>n;
        for(int i=1;i <= n;i++){
            k+=((i-1)*2+1)*i;
        }
        cout<<k<<" "<<2*n<<endl;
        for(int i=n;i>=1;i--){
            for(int j=1;j<=2;j++){
                cout<<j<<" "<<i<<" ";
                show(n);
            }
        }

    }
}