#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int i=2;
        int biggest_divisor=0;
        while (i <= sqrt(n)) {
            if (n % i == 0) {
                biggest_divisor = n / i;
                break;
            }
            i++;
        }
        if (biggest_divisor==0) {
            biggest_divisor = 1;
            i=n;
        }
        // we have now that biggest common divisor
        int multip1=1,multip2=i-multip1;
        cout<<biggest_divisor*multip1<<" "<<biggest_divisor*multip2<<endl;
    }
}