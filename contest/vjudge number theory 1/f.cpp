#include<iostream>
using namespace std;
#define ll long long

int main(){
    ll a,b;
    cin>>a>>b;
    a%=100;
    b%=100;
    if (b-a > 9){
        cout<< 0;
    }
    else {
        int prod=1;
        for (int i=a+1;i<=b;i++){
            prod = (prod*i)%10;
        }
        cout<< prod;
    }
}