#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

string add(string a,string b){
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    string res;
    int n=max(a.size(),b.size());
    while(a.size()<n){
        a+='0';
    }
    while(b.size()<n){
        b+='0';
    }
    int ret=0;
    for(int i=0;i<n;i++){
        int k = ret+a[i]+b[i]-'0'-'0';
        ret=0;
        if(k>9){
            ret=1;
            k-=10;
        }
        res+=(char)('0'+k);
    }
    if(ret==1){
        res+='1';
    }
    reverse(res.begin(),res.end());

    return res;
}

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s;cin>>s;
        string res="";res+=s[0];
        string sub="";sub+=s[0];
        for(int i=1;i<n;i++){
            string word=sub+'0';
            string curr="";curr+=s[i];
            word=add(word,curr);
            res=add(res,word);
            //cout<<"we just added "<<word<<endl;
            sub+=s[i];
        }
        int i=0;
        while(res[i]=='0'){
            i++;
        }
        while(i<res.size()){
            cout<<res[i];
            i++;
        }
        cout<<endl;
    }
}