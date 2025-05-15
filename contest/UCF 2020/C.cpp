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

int main(){fast();
    string s;cin>>s;
    int h,m;
    h = (s[0]-'0') *10 + s[1]-'0';
    m = (s[3]-'0') *10 + s[4]-'0';
    int diff = h*3600 + m *60 - h*60-m;
    int hours = diff/3600;
    diff -= hours * 3600;
    int minutes = diff/60;
    diff -= minutes * 60;
    if(hours<10)cout<<'0';
    cout<<hours<<":";
    if(minutes<10)cout<<'0';
    cout<<minutes<<":";
    if(diff<10)cout<<'0';
    cout<<diff;

    return 0;
}