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

ll round_(double x){
    if(x - (double)(ll)x > 0.5){
        return (ll)x +1;
    }
    return (ll)x;
}

int main(){fast();

        ll n;cin>>n;
        vector<ll> x(n);
        vector<ll> y(n);

        double xx = 0;
        double yy = 0;


        for(ll i=0;i<n;i++){
            cin>>x[i];
            xx += x[i];

            cin>>y[i];
            yy += y[i];

        }
        sort(all(x));
        sort(all(y));
        cout<<x[(n-1)/2]<<" "<<y[(n-1)/2]<<endl;
    return 0;
}

/*
 xx /= n;
        yy /= n;
        //cout<<xx;

        ll xxxx = (ll)xx;
        ll yyyy = (ll)yy;

        //cout<<xxxx<<endl;
        //cout<<yyyy<<endl;

        auto xxx  = lower_bound(all(x),xx);
        auto yyy = lower_bound(all(y),yy);

        //for(ll elem:x)cout<<elem<<" ";cout<<endl;
        //for(ll elem:y)cout<<elem<<" ";cout<<endl;
        //cout<< *xxx<<endl;
        //cout<< *yyy<<endl;

        cout << (*xxx == xxxx ? *xxx : *(xxx - 1) )<< " " << (*yyy == yyyy ? *yyy : *(yyy - 1) ) << endl;



*/