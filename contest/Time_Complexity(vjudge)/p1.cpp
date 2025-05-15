#include<iostream>

using namespace std;

int main(){
    int n,value;
    cin>>n;
    int last_input,max=0,res=1;
    cin>>last_input;
    for(int i=1;i<n;i++){
        cin>>value;
        if(value >= last_input){
            res++;
        }
        else{
            if (res>max){
                max=res;
            }
            res=1;
        }
        last_input=value;
    }
    if (res>max){
        max=res;
    }
    cout<<max<<endl;
}

