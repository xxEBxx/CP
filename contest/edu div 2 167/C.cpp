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
        int n;cin>>n;
        vector<int> first(n),second(n);
        for(int i=0;i<n;i++){
            cin>>first[i];
        }
        for(int i=0;i<n;i++){
            cin>>second[i];
        }
        int mv1=0,mv2=0;
        for(int i=0;i<n;i++){
            if(first[i]!=second[i]){
                if(first[i]>second[i])mv1+=first[i];
                else mv2+=second[i];
            }
        }
        for(int i=0;i<n;i++){
            if(first[i]==second[i]){
                if(first[i]==1){
                    if(mv1>mv2)mv2++;
                    else mv1++;
                }
                else{
                    if(mv1>mv2)mv1+=first[i];
                    else mv2+=first[i];
                }
            }
        }
        cout<<min(mv1,mv2)<<endl;
    }
    return 0;
}