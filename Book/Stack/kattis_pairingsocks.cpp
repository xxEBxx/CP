#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,value;cin>>n;n*=2;
    stack<int> original;
    stack<int> aux;
    while(n--){
        cin>>value;
        original.push(value);
    }
    int count =0;
    while(!original.empty()){
        if(aux.empty()){
            aux.push(original.top());
            original.pop();
            count++;
        }
        else{
            if(aux.top()==original.top()){
                aux.pop();
                original.pop();
                count++;
            }
            else{
                aux.push(original.top());
                original.pop();
                count++;
            }
        }
    }
    if(aux.empty()) {
        cout<<count<<endl;
    }
    else{
        cout<<"impossible";
    }

}