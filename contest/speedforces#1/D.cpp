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
    string a;cin>>a;
    int h=(a[0]-'0')*10+a[1]-'0',m=(a[3]-'0')*10+a[4]-'0';
    if(h>=12)h-=12;
    float angle_min=6*m,angle_hour=30*h+angle_min/12;
    cout<<angle_hour<<" "<<angle_min<<endl;
    return 0;
}