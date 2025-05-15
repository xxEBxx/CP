#include<iostream>
using namespace std;

int main(){
    int n=6;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int k=j;k<n;k++){
                for(int p=k;p<n;p++){
                    for(int r=p;r<n;r++){
                        if((i+j+k+p+r)%5 == 0)cout<<i<<j<<k<<p<<r<<endl;
                    }
                }
            }
        }
    }
}