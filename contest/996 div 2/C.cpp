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
        ll n,m;cin>>n>>m;
        string s;
        cin>>s;

        vector<vi> arr(n,vi(m,0));
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++)
                cin>>arr[i][j];
        }

//if i read D i fix the row , if i read R i fix the column
        ll current_i=0,current_j=0;
        for(ll i=0;i<s.size();i++){
            if(s[i]=='D'){
                ll sum=0;
                for(ll j=0;j<m;j++){
                    sum+=arr[current_i][j];
                }
                arr[current_i][current_j]=-sum;
                current_i++;
            }
            else{
                ll sum=0;
                for(ll ii=0;ii<n;ii++){
                    sum+=arr[ii][current_j];
                }
                arr[current_i][current_j]=-sum;
                current_j++;
            }

        }
        ll sum=0;
        for(ll i=0;i<n;i++){
            sum+=arr[i][m-1];
        }
        arr[n-1][m-1]=-sum;
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}