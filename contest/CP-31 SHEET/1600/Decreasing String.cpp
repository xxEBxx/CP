#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef pair<ll,ll> pl;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;

const ll maxn=(ll)1e6+7;
const ll mod=(ll)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int main(){fast();
    ll t;cin>>t;
    while(t--){
        string s;cin>>s;
        ll index;cin>>index;
        ll n=s.size();
//we try first to know the len of the string where he will
        while(n < index){
            index-=n;
            n--;
        }
        index--;//for 0 based
//know that i know the size of string at that poll and its exact index there
        string new_string="";
        ll k = s.size()-n;//k is left to remove
        for (char c : s) {
            while (!new_string.empty() && k > 0 && new_string.back() > c) {
                new_string.pop_back();
                k--;
            }
            new_string.push_back(c);
        }

        cout<<new_string[index];
    }
    return 0;
}