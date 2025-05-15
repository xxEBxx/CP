#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    unsigned long int t,n,a,b,f,value;
    cin>>t;
    for (int kk=0;kk<t;kk++){
        cin>>n>>f>>a>>b;
        int arr[n];
        for (int i=0;i<n;i++){
            cin>>value;
            arr[i]=value;
        }
        unsigned long int sum=0;
        for (int i=0;i<n-1;i++){
            sum+=min(a*(arr[i+1]-arr[i]),b);
        }
        if(sum<f){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

    }

}