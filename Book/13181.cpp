#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    while (getline(cin,s)){
        int max=0,n=s.size();
        int maxfirst=0,maxlast=0;
        int j=0;
        while (j < n && s[j] == '.') {
            maxfirst++;
            j++;
        }
        j=n-1;
        while (j>-1 && s[j] == '.') {
            maxlast++;
            j--;
        }
        j=0;
        while (j<n) {
            int count=0;
            while (j < n && s[j] == '.') {
                count++;
                j++;
            }
            if (count > max){
                max=count;
            }
            while (j < n && s[j] == 'X') {
                j++;
            }

        }

        int a=maxfirst-1,b=maxlast-a,c=max=(max-1)/2;
        int res=0;
        if(a>b){
            res=a;
        }
        else{
            res=b;
        }
        if(c>res){
            res=c;
        }
        cout<<res<<endl;
    }
}