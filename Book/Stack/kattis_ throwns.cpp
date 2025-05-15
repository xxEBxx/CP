#include<bits/stdc++.h>

using namespace std;

int new_kid(int kid,int n){
    kid= kid%n;
    if(kid<0){
        kid+=n;
    }
    return kid;
}

int main(){
    int n,k,kid=0;
    cin>>n>>k;
    cin.ignore();
    stack<int> s;
    string line;
    getline(cin, line);
    stringstream ss(line);
    int value;
    string token;
    while (ss >> token) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
                value=stoi(token);
                if(!s.empty())kid=s.top();
                else kid=0;
                s.push(new_kid(kid+value,n));
                //cout<<"just pushed"<<new_kid(kid+value,n);
            } else {
                ss>>value;
                //cout<<"will pop m times"<<value;
                for(int i=0;i<value;i++){
                    //cout<<"POPP";
                    s.pop();
                }
            }

    }
if(s.empty())cout<<0;
else cout<<s.top();
}