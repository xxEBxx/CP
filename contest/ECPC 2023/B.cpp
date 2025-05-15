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

int main(){fast();
    int t;cin>>t;
    while(t--){
        string s;
        cin >> s;
        ll a= 1;
        for(int i=1;i<s.length();i++){
            if(s[i] != s[i-1])
                a++;
        }
        ll b = 1;
        ll c = 1;
        for(int i=1;i<s.length();i++){
            if(s[i] == s[i-1])
                c++;
            else{
                b *= c;
                b%=mod;
                c = 1;
            }
        }
        b*= c;
        b%=mod;
        cout<<a<< " " << b << endl;

    }
    return 0;
}