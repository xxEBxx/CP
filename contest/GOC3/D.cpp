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
    int t;cin>>t;
    while(t--){
        int nn, mm, temp;
        cin >> nn >> mm;
        int n, m;
        n = min(nn, mm);
        m = max(nn, mm);
        if (n % 2 == 0)
            cout << "Anas"<<endl;
        else {
            if (m % 2 == 0)
                cout << "Anas"<<endl;
            else
                cout << "Zakariaa"<<endl;
        }
    }
    return 0;
}