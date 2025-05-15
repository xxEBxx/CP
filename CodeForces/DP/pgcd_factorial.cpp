#include<iostream>
#include<algorithm>
using namespace std;

int facto(long x){
    int prod=1;
    for (int i=2;i<=x;i++){
        prod *= i;
    }
    return prod;
}

int main(){
    int a,b;
    cin>>a>>b;
    cout<<facto(min(a,b));
}