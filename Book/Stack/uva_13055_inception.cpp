#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;cin>>n;
    cin.ignore();
    string a,b;
    stack<string> s;
    while(n--){
    cin>>a;
    if(a=="Sleep"){
        cin>>b;
        s.push(b);
    }
    else if (a=="Test"){
        if(s.empty()){
            cout<<"Not in a dream"<<endl;
        }
        else{
            cout<<s.top()<<endl;
        }
    }
    else{
        if(!s.empty()){
            s.pop();
        }
    }
    }
}
