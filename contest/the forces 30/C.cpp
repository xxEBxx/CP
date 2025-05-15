#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;
        cin>>n;
        int k=sqrt(n);
        //it is either k or k+1;
        if(n/(k+1) + k  <  n/k +k-1){
            k++;
        }

    }
}