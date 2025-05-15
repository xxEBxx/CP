#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        //1 will be touched whenever we have a prime number
        //can
        int max_n=0;//max n is the max int st n>(1<<max_n// )
        while(n >= (1<<max_n) ){
            max_n++;
        }
        max_n--;
        cout<<(1<<max_n)<<endl;
    }
}