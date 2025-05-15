//link :https://vjudge.net/problem/UVA-990
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

ll dp[31][1001];//31 is number of elements and 1000 is number of seconds he can have at most

int main(){fast();
    string line;bool first=true;
    while (getline(cin, line)) {
        if(!first)cout<<endl;
        first=false;
        if (line.empty()) continue; // Skip blank lines
        memset(dp,0,sizeof(dp));
        stringstream ss(line);
        ll t, w;
        ss >> t >> w; // Read t and w
        getline(cin, line); // Read the number of treasures line
        stringstream ss2(line);
        ll n;
        ss2 >> n;

        vector<pair<ll, ll>> arr(n); // Store depth and gold
        for (ll i = 0; i < n; i++) {
            cin>>arr[i].f>>arr[i].s;
            //here .f is depth we will make it price
            arr[i].f *= 3*w;
        }
        for(ll mon=0;mon<=t;mon++){
            if(arr[0].f <= mon )dp[0][mon]=arr[0].s;
        }
        for(ll i=1;i<n;i++){
            for(ll mon=0;mon <= t;mon++){
                dp[i][mon]=dp[i-1][mon];//not taking;
                if(mon >= arr[i].f){
                    dp[i][mon]=max(dp[i][mon],
                                   arr[i].s + dp[i-1][mon-arr[i].f]
                    );//this is taking the i'th element
                }
            }
        }
        ll index=n-1,price=t;
        cout<<dp[n-1][t]<<endl;
        vector<ii> output;
        while(price >= 0 && index > 0){
            //cout<<"here is index and price"<<index<<" "<<price<<endl;
            if(dp[index][price] > dp[index-1][price]){
                //this means he bought the i'th element
                price -= arr[index].f;
                output.push_back(arr[index]);
            }
            index--;
        }
        if(price >= arr[0].f)output.push_back(arr[0]);
        reverse(all(output));
        cout<<output.size()<<endl;
        for(ii elem : output)cout<<elem.f/(3*w)<<" "<<elem.s<<endl;
    }
    return 0;
}

