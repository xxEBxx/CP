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
    int n,m;cin >> n >>m;

        vector<int> a(n);
        vector<int> b(m);
        vector<vector<int>> ab(n,vector<int>(m));
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i]%b[i] == 0){
                ab[i][j] = a[i]/b[j];
            }else{
                cout <<"No"<<endl;
                return 0;
            }
        }
    }

    cout << "Yes\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << ab[i][j] << " ";
        }
        cout << "\n";
    }


    return 0;
}