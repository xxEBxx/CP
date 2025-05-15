#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first

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

int main(){fast();
    ll t;cin>>t;
    while(t--){
        string s;cin>>s;
        ll n=(ll)s.size(),start=0,end=n/2-1;
        while(s[start]==s[n-start-1]){
            start++;
        }
        while(s[end]==s[n-end-1]){
            end--;
        }

        //now we have the substring that need fix
        string p1,p2;
        for(ll i=start;i<=end;i++){
            p1+=s[i];
        }
        for(ll i=n-end-1;i<=n-start-1;i++){
            p2+=s[i];
        }
        string ller;
        for(ll i=end+1;i<n-end-1;i++){
            ller+=s[i];
        }
        //cout<<p1<<" "<<p2<<endl;
        s=p1+ller;s+=p2;
        sort(all(p1));sort(all(p2));
        if(p1==p2){
            cout << p1.size() << endl;
        }
        else {
            vector<ll> state1(30,0),state2(30,0);
            n=(ll)s.size();
            for(ll i=0;i<n;i++){
                state1[s[i]-'a']++;
            }
            ll res=n;
            for(ll i=0;i<n;i++){
                state2[s[i]-'a']++;
                bool eq=true;
                for(ll j=0;j<30;j++){
                    if((state1[j]/2) > state2[j]){
                        eq=false;
                        break;
                    }
                }
                if(eq){
                    res = min(res,i+1);
                }
            }
            reverse(all(s));
            state2.assign(30,0);
            for(ll i=0;i<n;i++){
                state2[s[i]-'a']++;
                bool eq=true;
                for(ll j=0;j<30;j++){
                    if((state1[j]/2) > state2[j]){
                        eq=false;
                        break;
                    }
                }
                if(eq){
                    res = min(res,i+1);
                }
            }
            cout<<res<<endl;
        }
    }
    return 0;
}

