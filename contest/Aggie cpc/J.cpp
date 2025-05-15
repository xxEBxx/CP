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

bool work(ll intense,ll d,ll E , ll dp){
    return E <= dp*(intense + (d - intense)/2);
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
        cout << mindays  * 4 * (tp + tm)<<endl;
    }
    else if(d1 == mindays){
        cout << mindays<<endl;
        ll low = 0;
        ll high = mindays;
        while (high - low > 1){
            ll mid = (low + high)/2;
            if(work(mid,mindays,neededscore2,dm)){
                high = mid;
            }else{
                low = mid + 1;
            }
        }
        ll res;
        if(work(low,mindays,neededscore2,dm)) {
            res =    4*mindays*tp+ ( 4*low + (mindays - low)/2)*tm;
        }
        else{
            res =    4*mindays*tp+ ( 4*high + (mindays - high)/2)*tm;

        }

        cout << res<<endl;

    }
    else{
        cout << mindays<<endl;
        ll low = 0;
        ll high = mindays;
        while (high - low > 1){
            ll mid = (low + high)/2;
            if(work(mid,mindays,neededscore1,dp)){
                high = mid;
            }else{
                low = mid + 1;
            }
        }
        ll res;
        if(work(low,mindays,neededscore1,dp)) {
            res =    4*mindays*tm + ( 4*low + (mindays - low)/2)*tp;
        }
        else{
            res =    4*mindays*tm  + ( 4*high + (mindays - high)/2)*tp;

        }

        cout << res<<endl;

    }




    return 0;
}
