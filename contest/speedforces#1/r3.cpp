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

const int maxn=(int)1e5*2+7;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

ll n,target;
int arr[3][maxn];

int check(int i,int j){
    //j is the end of the one before
    if(j==n)return -1;
    ll sum=0,k;
    for(k=j;k<n;k++){
        sum+=arr[i][k];
        if(sum >= target) {
            return k;
        }
    }
    return -1;
}

void solve(){
    int la,ra,lb,rb,lc,rc;

    la=0;
    ra=check(0,0);
    if(ra!=-1){
        lb=ra+1;
        rb=check(1,lb);
        if(rb!=-1){
            lc=rb+1;
            rc=check(2,lc);
            if(rc!=-1){
                cout<<1+la<<" "<<1+ra<<" "<<1+lb<<" "<<1+rb<<" "<<1+lc<<" "<<1+rc<<endl;
                return;
            }
        }
        lc=lb;
        rc=check(2,lc);
        if(rc!=-1){
            lb=rc+1;
            rb=check(1,lb);
            if(rb!=-1){
                cout<<1+la<<" "<<1+ra<<" "<<1+lb<<" "<<1+rb<<" "<<1+lc<<" "<<1+rc<<endl;
                return;
            }
        }
    }
    lb=0;
    rb= check(1,lb);
    if(rb!=-1){
        la=rb+1;
        ra=check(0,la);
        if(ra!=-1){
            lc=ra+1;
            rc=check(2,lc);
            if(rc!=-1){
                cout<<1+la<<" "<<1+ra<<" "<<1+lb<<" "<<1+rb<<" "<<1+lc<<" "<<1+rc<<endl;
                return;
            }
        }
        lc=la;
        rc=check(2,lc);
        if(rc!=-1){
            la=rc+1;
            ra=check(0,la);
            if(ra!=-1){
                cout<<1+la<<" "<<1+ra<<" "<<1+lb<<" "<<1+rb<<" "<<1+lc<<" "<<1+rc<<endl;
                return;
            }
        }
    }
    //we start with c;
    lc=0;
    rc=check(2,0);
    if(rc!=-1){
        la=rc+1;
        ra=check(0,la);
        if(ra!=-1){
            lb=ra+1;
            rb=check(1,lb);
            if(rb!=-1){
                cout<<1+la<<" "<<1+ra<<" "<<1+lb<<" "<<1+rb<<" "<<1+lc<<" "<<1+rc<<endl;
                return;
            }
        }
        lb=la;
        rb=check(1,lb);
        if(rb!=-1){
            la=rb+1;
            ra=check(0,la);
            if(ra!=-1){
                cout<<1+la<<" "<<1+ra<<" "<<1+lb<<" "<<1+rb<<" "<<1+lc<<" "<<1+rc<<endl;
                return;
            }
        }
    }

    cout<<-1<<endl;

}
int main(){fast();
    int t;cin>>t;
    while(t--){

        cin>>n;
        ll tot=0;
        for(int j=0;j<3;j++){
            for (int i = 0; i < n; i++) {
                cin >> arr[j][i];
                tot += arr[j][i];
            }
        }
        tot/=3;
        target=tot/3;
        if(tot%3 != 0)target++;
        //cout<<target<<endl;
        solve();

    }
    return 0;
}