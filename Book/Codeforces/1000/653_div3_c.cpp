#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        cin.ignore();
        string arr;getline(cin,arr);
        stack<char> s;
        for(int i=0;i<n;i++){
            if(s.empty()){
                s.push(arr[i]);
            }
            else{
                if(arr[i]==')' && s.top()=='('){
                    s.pop();
                }
                else{
                    s.push(arr[i]);
                }
            }
        }
        cout<<s.size()/2<<endl;
    }
}