#include<iostream>
#include<string>
using namespace std;

int main(){
    int t,n;
    cin>>t;
    string s;
    for (int k=0;k<t;k++){
        cin>>n;
        cin.ignore();
        getline(cin,s);
        int i=0,j=n-1;
        while (s[i]=='W'){
            i++;
        }
        while (s[j]=='W'){
            j--;
        }
        cout <<j-i+1<<endl;
    }
}