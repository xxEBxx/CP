#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;cin>>n;
    while(n!=1){
        cout<<n<<" ";
        if(n%2==1) n=3*n+1;
        else n=n>>1;
    }
cout <<1;
}