#include<bits/stdc++.h>

using namespace std;

string solve(vector<int> arr){
    int n=arr.size(),element=1,i=0;
    stack<int> s;
    //there is 2 things 3mer stack w moraha 5wi stack
    //f koula i
    while(i<n && element<n+2) {
        if(s.empty()){
            if(arr[i]!=element){
                s.push(element);
                element++;
            }
            else{
                i++;
                element++;
            }
        }
        else{
            //cout<<"top: "<<s.top()<<"element"<<element<<" i: "<<i<<endl;
            if(arr[i]==s.top()){
                s.pop();
                i++;
            }
            else{
                s.push(element);
                element++;
            }
        }
    }
    if(s.empty()){
        return "Yes";
    }
    return "No";
}

int main(){
    int n;
    while(cin>>n) {
        if (n == 0) {
            return 0;
        }
        int first_value;
        while(cin >> first_value){
            if (first_value == 0) {
                break;
            }
        vector<int> a(n);
        a[0]=first_value;
        for (int i = 1; i < n; i++) {
            cin >> a[i];
        }
        cout<<solve(a)<<endl;
        }
        cout<<'\n';
    }

}