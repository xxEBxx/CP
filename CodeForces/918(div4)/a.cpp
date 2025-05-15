#include<iostream>

using namespace std;
int main(){
    int t,a,b,v;
    cin>>t;
    for (int k=0;k<t;k++){
        cin>>a;
        cin>>b;
        cin>>v;
        if (b == v){
            cout<<a;
        }
        else if (a==b){
            cout <<v;
        }
        else{
            cout<<b;
        }
        cout<<"\n";
    }
}