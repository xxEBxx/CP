#include<iostream>
#include<string>
using namespace std;
int main (){
    string s;
    cin>>s;
    int n=s.size();
    if (s[0]=='0' or s[n-1]=='0'){
        cout <<"NO";
        return 0;
    }
    for (int i=0;i<n;i++){
        if (s[i]=='0' || s[i]=='1' || s[i]=='8' || s[i]=='6' || s[i]=='9'){
            continue;
        }
        else{
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}