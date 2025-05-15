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

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const int maxn=(int)2*1e5+7;
const int mod=(int)1e9+7;


string s;
bool work(int x){
    int n=s.size();

    for(int i=0 ; i < n-x-x;i++){
        bool loc=true;
        for(int j=0;j<x;j++){
            if(s[i+j] != s[i+j+x] && s[i+j]!='?' && s[i+j+x]!='?'){
                loc=false;
                break;
            }
        }

        if(loc)
            return true;
    }
    return false;
}

int main(){fast();
    int t;cin>>t;
    while(t--){cin>>s;
        int n;n=(int)s.size();
        int a=0,b=n,c;
        while(a+1 < b){
            c=(a+b)/2;
            if(work(c))
                a=c;
            else
                b=c-1;
        }
        if(work(b))cout<<2*b<<endl;
        else cout<<a*2<<endl;
    }
    return 0;
}