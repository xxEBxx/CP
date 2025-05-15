#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;

const int maxn=(int)1e6+7;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

string c(string a,string b){
    int s1=1,s2=1;
    for(int i=0;i<a.size();i++){
        s1*=a[i]-'0';
    }
    for(int i=0;i<b.size();i++){
        s2*=b[i]-'0';
    }
    //cout<<a<<" "<<b<<endl;
    //cout<<s1<<s2<<endl;
    if(s1 > s2)return a;
    return b;
}

int main(){fast();
    string a,b;cin>>a>>b;

    if(b.size() > a.size()){
        string res="";
        res+=(char)(b[0]-1);
        for(int i=1;i<b.size();i++){
            res+='9';
        }
        if(res[0]=='0')res.erase(0,1);
        res=c(res,b);
        cout<<res;

    }
    else{
        string res="";
        int i=0;
            for(i;i<b.size();i++){
                if(a[i]==b[i] || b[i]=='1' || i==b.size()-1){
                    res+=b[i];
                }
                else break;
        }
        if(i<b.size())res += (char) (b[i] - 1);
        i++;
        for (i; i < b.size(); i++) {
            res += '9';
        }
        res=c(res,b);
        cout<<res;
    }
    return 0;
}
