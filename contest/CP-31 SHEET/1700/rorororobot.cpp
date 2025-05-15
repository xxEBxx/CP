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

int n,m,q;
int arr[maxn],st[maxn][21];


int query(int l,int r){
    //we want max elem between l and r
    int diff=r-l;
    int res=0;
    for(int j = 20;j>=0;j--){
        if(diff & (1<<j)){
            res=max(res,st[l][j]);
            l += (1<<j);
        }
    }

    return res;
}

int main(){fast();

    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>arr[i];
        st[i][0] = arr[i];
    }

    for(int j=1;j<20;j++){
        for(int v =0;v<m;v++){
            if(v+(1<<(j-1)) < m)
                st[v][j]= max(st[v][j-1],st[v+(1<<(j-1))][j-1]);
        }
    }


    cin>>q;
    for(int i=0;i<q;i++){
        int xs,ys,xf,yf,k;
        xs--;ys--;xf--;yf--;
        cin>>xs>>ys>>xf>>yf>>k;
        //cout<<"here is n and max in subsegmetn"<<n<<" "<<query(min(ys,yf),max(ys,yf))<<" "<<k<<endl;
        int passage_from = query(min(ys,yf),max(ys,yf))+1;
        bool dayz=false;

        if(xs + k * ((n-xs)/k) >= passage_from ){
            dayz=true;
        }

        if(abs(yf-ys)%k==0 && abs(xf-xs)%k==0 && dayz)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;

    }

    return 0;
}