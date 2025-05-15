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
    int n;cin>>n;
    string s;cin>>s;
    stack<int> a;
    for(int i=0;i<n;i++){
        if(a.empty()){
            a.push(0);
            cout<<0;
            continue;
        }
        if(s[i]=='('){
            cout<<1-a.top();
            a.push(1-a.top());
        }
        else{
            cout<<a.top();
            a.pop();
        }
    }
    return 0;
}