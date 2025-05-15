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

const int maxn=(int)1e6+2;
const int mod=(int)1e9+7;

vector<vi> dividor(maxn);

void esthratos(){
    for(int i=2;i<maxn;i++){
        if(dividor[i].empty()) {
            for (int j = i; j < maxn; j += i) {
                dividor[j].push_back(i);
            }
        }
    }
}

int main(){fast();
    esthratos();
    int n; cin >> n;
    map<int, int> index;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        int val; cin >> val;
        arr[i] = val;
        if (index.count(val) == 0)
            index[val] = i + 1;
    }

    sort(all(arr));
    arr.erase(unique(all(arr)), arr.end());

    n=arr.size();
    map<int,int> best_prime;
    vector<int> ans(n,1);

    int max_elem =1,elem=arr[0];
    for(int i=0;i<n;i++){
        int best = 0;
        for(auto d : dividor[arr[i]]){
            best = max(best,best_prime[d]);
        }
        ans[i] = best+1;
        for(auto d : dividor[arr[i]]){
            best_prime[d] = ans[i];
        }
        if(ans[i] > max_elem){
            max_elem = ans[i];
            elem = arr[i];
        }

    }

    vector<int> res;
    res.push_back(elem);
    for(int i=n-1 ; i>=0 ; i--){
        if(ans[i] == (max_elem-1) && gcd(elem,arr[i])>1 ){
            max_elem--;
            elem=arr[i];
            res.push_back(elem);
        }
    }

    reverse(all(res));
    cout<<res.size()<<endl;
    for(auto k : res){
        cout<<index[k]<<" ";
    }



    return 0;
}