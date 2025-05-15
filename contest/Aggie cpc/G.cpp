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

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const ll maxn=(ll)2*1e5+7;
const ll mod=(ll)1e9+7;

int work(ll llense,ll d,ll E , ll dp){
    return dp*(llense + (d - llense)/2) - E;
}

int main(){fast();
    ll sp,sm,dp,dm,tp,tm,e;cin >> sp >>sm>>dp>>dm>>tp>>tm>>e;
    ll neededscore1 =  e - sp;
    ll neededscore2 = e - sm;
    ll d1 = neededscore1/dp  +(neededscore1%dp ? 1 : 0);
    ll d2 = neededscore2/dm  +(neededscore2%dm ? 1 : 0);

    ll mindays = max(d1,d2);

    if (d1 == d2){
        cout << mindays<<endl;
        cout << mindays  * 4ll * (tp + tm)<<endl;
    }
    else if(d1 == mindays){
        cout << mindays<<endl;
        ll low = 0;
        ll high = mindays;

        while (high - low > 1){
            ll mid = (low + high)/2;
            if(work(mid,mindays,neededscore2,dm) >= 0){
                high = mid;
            }else{
                low = mid + 1;
            }
        }
        ll res;
        if(work(low,mindays,neededscore2,dm) >= 0) {
            res =    4ll*mindays*tp+ ( 4ll*low + (mindays - work(low,mindays,neededscore2,dm) - low) )*tm;
        }
        else{
            res =    4ll*mindays*tp+ ( 4ll*high + (mindays - work(low,mindays,neededscore2,dm)  - high))*tm;

        }

        cout << res<<endl;

    }
    else{
        cout << mindays<<endl;
        ll low = 0;
        ll high = mindays;
        while (high - low > 1){
            ll mid = (low + high)/2;
            if(work(mid,mindays,neededscore1,dp) >= 0){
                high = mid;
            }else{
                low = mid + 1;
            }
        }
        ll res;
        if(work(low,mindays,neededscore1,dp) >= 0) {
            res =    4ll*mindays*tm + ( 4ll*low + (neededscore1 - low)*2)*tp;
        }
        else{
            res =    4ll*mindays*tm  + ( 4ll*high + (neededscore1 - high)*2)*tp;

        }

        cout << res<<endl;

    }

    return 0;
}
