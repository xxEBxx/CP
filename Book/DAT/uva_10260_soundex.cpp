#include<bits/stdc++.h>

using namespace std;

char char_to_element(string all,char x){
    int index=-1;
    for(int i=0;i<all.size();i++){
        if(x==all[i]){
            index=i;
            break;
        }
    }
    if (index==-1) return '0';
    if(index<4)return '1';
    if (index<12)return '2';
    if(index < 14) return '3';
    if(index<15)return '4';
    if(index<17)return '5';
    return '6';
}

int main(){
    string s;
    string all="BFPVCGJKQSXZDTLMNR";
    map<char,char> m;
    for(int i=0;i<all.size();i++){
        m[all[i]]= char_to_element(all,all[i]);
    }
    while(cin>>s) {
        string res="",preprocess="";preprocess+=s[0];
        for(int i=1;i<s.size();i++){
            if(m[s[i]]!=m[preprocess[preprocess.size()-1]]){
                preprocess+=s[i];
            }
        }
        //cout<<preprocess;
        s=preprocess;
        for(int i=0;i<s.size();i++){
            if(m[s[i]]-'0'>0 &&m[s[i]]-'0'<7){
                res+=m[s[i]];
            }
        }
        cout<<res<<endl;
    }
}