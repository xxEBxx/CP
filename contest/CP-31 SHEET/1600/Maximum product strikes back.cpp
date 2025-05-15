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
        ll n;cin>>n;
        vector<vector<ll>> arr_of_arrs;
        vi current;
        for(ll i=0;i<n;i++){
            ll a;cin>>a;
            if(a==0) {
                arr_of_arrs.push_back(current);
                current.clear();
            }
            else {
                current.push_back(a);
                //2 power 0 or 2 power 1 then we do sum instead of products
            }
        }
        if(!current.empty())
            arr_of_arrs.push_back(current);

        ll start=n,end=n,answer=0,current_start=0;
        for(auto arr : arr_of_arrs){
            ll first_neg=-1,last_neg=-1,count_neg=0,len=(ll)arr.size();
            for(ll i=0;i<len;i++){
                if(arr[i] < 0){
                    count_neg++;
                    last_neg = i;
                    if(first_neg == -1)
                        first_neg = i;
                }
            }
            if(count_neg%2 == 0){
                ll res=0;
                for(auto elem : arr)
                    res += abs(elem/2);
                if(res > answer){
                    start = current_start;
                    end = current_start+len;
                    answer=res;
                }
            }
            else {
                ll res1 = 0, res2 = 0;
                for (ll i = first_neg+1; i < len; i++)
                    res2 += abs(arr[i]/2);

                for (ll i = 0; i < last_neg; i++)
                    res1 += abs(arr[i]/2);

                if (res1 >= res2 && res1 > answer) {
                    start = current_start ;
                    end = current_start + last_neg;
                    answer=res1;
                } else if (res2 >= res1 && res2 > answer) {
                    answer=res2;
                    start = current_start + first_neg+1;
                    end = current_start + len;
                }
            }
            current_start += len+1;// +1 for the 0 we removed
        }
        cout<<start<<" "<<n-end<<endl;
    }
    return 0;
}