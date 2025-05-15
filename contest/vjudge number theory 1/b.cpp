#include<iostream>
using namespace std;
int main(){
    long long n;
    int k,counter=1;
    cin >> n>>k;
    for (long long i=2;i<n+1;i++){
        if (n%i==0){
            counter++;
        }
        if (counter==k){
            cout<<i;
            return 0;
        }
    }
    cout<<-1;
}