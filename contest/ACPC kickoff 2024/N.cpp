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

const int maxn=(int)1e7+2;
const int mod=(int)1e9+7;

vector<unordered_map<int,int>> m;
vvi dividors(maxn);

void estrathos(){

    for(int i=2;i<maxn;i++){
        if(dividors[i].size() == 0) {
            for (int j =  i; j < maxn; j++) {
                dividors[j].push_back(i);
            }
        }
    }

    for(int i = 2 ;i<maxn;i++){
        for(int div : dividors[i]){
            int a = 0;
            ll pp = 1;
            while(i % pp == 0){

            }
        }
    }

}

int solve()

int main(){fast();
    int t;cin>>t;
    while(t--){
        int n,x;cin>>n>>x;
        vector<int> arr;
        for(int i=0;i<n;i++){
            int val;cin>>val;
            if(x % arr[i] == 0 )
                arr.push_back(val);
        }
        n = arr.size();



    }
    return 0;
}