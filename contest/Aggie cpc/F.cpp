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
    map<int,int> m;
    int n;cin>>n;

    int S,L;cin>>S>>L;
    m[S] = 0;
    m[L] = 0;

    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        if(b<S || a>L)continue;
        if(a<S)
            a=S;
        if(b>L)
            b=L;
        m[a]++;
        m[b]--;
    }
    auto pointer = m.begin();

    int curr=0;

    map<int,int> res;

    while( pointer != m.end() && next(pointer) != m.end() ){
        int f = pointer->f,s=pointer ->s;
        pointer=next(pointer);
        //handle curr
        curr += s;

        //handle new map
        res[curr] += min(pointer->f,L+1) - f;
    }
    int a=0;
    for(int i=0;i<n;i++){
        a+=res[i];
        cout<<a<<" ";
    }

    return 0;
}