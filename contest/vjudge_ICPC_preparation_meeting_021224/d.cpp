#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int kk=0;kk<t;kk++){
        int n;
        cin>>n;
        cin.ignore();
        string s;
        getline(cin,s);
        reverse(s.begin(),s.end());
        int curr=0;
        string res="";
        while(curr<s.length()){
            if (curr!=0){
                res+=".";
            }
            //if V;
            if(s[curr]=='e' || s[curr]=='a'){
                res+=s[curr];
                res+=s[curr+1];
                curr=curr+2;
            }
            else{
                res+=s[curr];
                res+=s[curr+1];
                res+=s[curr+2];
                curr=curr+3;
            }

        }
        reverse(res.begin(),res.end());
        cout<<res<<endl;
    }
}
