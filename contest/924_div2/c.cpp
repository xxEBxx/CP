#include<iostream>

using namespace std;

int main(){
    int t,n,n,x;
    cin>>t;
    for (int kk=0;kk<n;kk++){
        cin>>n>>x;
        for(int k=x;k<n;k++){
            int count=0;
            if(n%(2*k-2)==x || n%(2*k-2)==2*k-x){
                count++;
            }
            cout<<count<<endl;
        }
    }
}