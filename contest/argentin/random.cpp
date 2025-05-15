#include<iostream>

using namespace std;

bool good(string a){
    for(int i=0;i<a.size()-1;i++){
        if(a[i]==a[i+1])return false;
    }
    return true;
}

int main(){
    int n;cin>>n;
    while(n--){
        int s,t;cin>>s>>t;
        string a,b;cin>>a>>b;
        bool zero=false,one=false;
        for(int i=0;i<s-1;i++){
            if(a[i]==a[i+1]){
                if(a[i]=='1')one=true;
                else zero=true;
            }
        }
        if(!zero && !one){
            cout<<"Yes"<<endl;
        }
        else if(!good(b)){
            cout<<"No"<<endl;
        }
        else if(zero && one){
            cout<<"No"<<endl;
        }
        else if (zero && (b[0]=='0' || b[t-1]=='0')){
            cout<<"No"<<endl;
        }
        else if(one && (b[0]=='1' || b[t-1]=='1')){
            cout<<"No"<<endl;
        }
        else{
            cout<<"Yes"<<endl;
        }
    }
}