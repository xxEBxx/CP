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
    int n,k;
    cin>>n>>k;
    vi arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    map<string,int> m;
    for(int i=0;i<k;i++){
        string f;cin>>f;
        m[f]++;
    }
    vi fruit;
    for(auto elem:m){
        fruit.push_back(elem.s);
    }

    int res1=0,res2=0;
    sort(all(fruit));
    reverse(all(fruit));
    sort(all(arr));
    for(int i=0;i<fruit.size();i++){
        res1+=arr[i]*fruit[i];
    }
    reverse(all(arr));
    //reverse(all(fruit));
    for(int i=0;i<fruit.size();i++){
        res2+=arr[i]*fruit[i];
    }

    cout<<res1<<" "<<res2<<endl;

    return 0;
}