#include<bits/stdc++.h>
using namespace std;

//next of x is (x+1)/2

int main(){
    //if we divide the array k time when
    //they will meet
    int n,i,j;
    while (cin>>n>>i>>j){
        vector <int >A,B;
        int l=n+1;
        while (l--){
            A.push_back(i);
            B.push_back(j);
            i=(i+1)/2;
            j=(j+1)/2;
        }
        for(int a=0;a<n+1;a++){
            //cout<<"A and B"<<A[a]<<B[a];
            if (A[a]==B[a]){
                cout<<a<<endl;
                break;
            }
        }
    }
}