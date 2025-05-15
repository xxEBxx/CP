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

const int maxn=100;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}
int dp[101][101];
vi get_lsp(string s){
    int j=0,i=1,n=s.size();
    vi res(n,0);
    while(i<n){
        if(s[i]==s[j]){
            j++;
            res[i]=j;
            i++;
        }
        else if(j>0){
            j=res[j-1];
        }
        else{
            i++;
        }
    }
    return res;
}

bool contains(string t,string s){
    int i=0,j=0,n=t.size(),m=s.size();
    if(m>n)return 0;
    if(m==n) return t==s;
    vi lsp= get_lsp(s);
    while(i<n && j<m){
        if(t[i]==s[j]){
            i++;j++;
        }
        else if(j>0){
            j=lsp[j-1];
        }
        else{
            i++;
        }
    }
    return j==m;
}

string solve(string a,string b,string virus){
    if(a.size()>b.size()){
        string temp=a;
        a=b;
        b=temp;
    }
//here a is always smaller so we iterate over it
    int i=0,j=0,n=a.size(),m=b.size();
    string res="";
    for(i=0;i<n;i++){

    }
}

int main(){fast();
    int t;cin>>t;
    while(t--){

    }
    return 0;
}