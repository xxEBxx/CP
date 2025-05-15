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

vvi dividor(maxn);

void estrathos(){
    for(int i=1;i<maxn;i++){
        for(int j=i;j<maxn;j+=i){
            dividor[j].push_back(i);
        }
    }
}

int main(){fast();
    estrathos();
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        vector<int> arr(n);
        int maxm=0;
        for(int i=0;i<n;i++) {
            cin >> arr[i];
            maxm=max(maxn,arr[i]);
        }
        vi made(m+1,0);
        sort(all(arr));
        int res=1e9,i=0,j=0,count=0;
        for(auto div : dividor[arr[0]]) {
            if(div <= m){
                if (made[div] == 0)count++;
                made[div] = 1;
            }
        }

        while(j<n){
            if(count>=m) {
                res = min(res, arr[j] - arr[i]);

                for(auto div : dividor[arr[i]]){
                    if(div<=m){
                        made[div]--;
                        if (made[div] == 0)count--;
                    }
                }
                i++;
            }
            else{
                j++;
                if(j==n)break;
                for(auto div : dividor[arr[j]]){
                    if(div<=m){
                        if (made[div] == 0)count++;
                        made[div]++;
                    }
                }
            }
        }

        if(res>1e7)
            cout<<-1<<endl;
        else
            cout<<res<<endl;

    }


    return 0;
}