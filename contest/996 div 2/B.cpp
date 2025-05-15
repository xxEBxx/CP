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
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> arr(n),goal(n),diff(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=0;i<n;i++){
            cin>>goal[i];
        }
        int need=0,amount_needed=0;
        for(int i=0;i<n;i++){
            diff[i]=arr[i]-goal[i];
            if(diff[i]<0) {
                need++;
                amount_needed=diff[i];
            }
        }
        //cout<<need<<amount_needed<<endl;
        if(need==0)
            cout<<"YES"<<endl;
        else if(need>1)
            cout<<"NO"<<endl;
        else{
            bool valid=true;
            for(int i=0;i<n;i++){
                if (diff[i]<0)continue;
                else{
                    if(diff[i] < -amount_needed){
                        valid=false;
                        break;
                    }
                }
            }
            if(valid)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }

    }
    return 0;
}