#include<iostream>
#include<cmath>
using namespace std;

int main(){
    long long n;
    cin>>n;
    cout << 2*3*(long long)pow(4,n-2) + (n-3)*9*(long long)pow(4,n-3);
}