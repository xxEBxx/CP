#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while(cin>>n){
        if(n==0){
            return 0;
        }
        int turn=1 ,num1=0,num2=0;
        bitset<32> bit(n);
        //cout<<bit<<endl;
        for(int i=0;i<32;i++){
            if(!bit.test(i)){
                continue;
            }
            //cout<<"i "<<i<<" num1 "<<num1<<" num2 "<<num2;
            if(turn){
                turn=0;
                num1+=(1<<i);
            }
            else{
                turn=1;
                num2+=(1<<i);
            }
            //cout<<"new i"<<i<<" num1 "<<num1<<" num2 "<<num2;
        }
        cout<<num1<<" "<<num2<<endl;
    }
}