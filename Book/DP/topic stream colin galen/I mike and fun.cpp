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
    int n,m,q;
    cin>>n>>m>>q;
    vvi arr(n,vi(m));
    vi scores(n,0);
    for(int i=0;i<n;i++){
        int score=0,current=0;
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            if(arr[i][j]==1){
                current++;
            }
            else{
                current=0;
            }
            score=max(score,current);
        }
        scores[i]=score;
    }

    //for(int elem : scores)cout<<elem<<" ";
    for(int i=0;i<q;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        arr[a][b]=1-arr[a][b];
        int score=0,current=0;
        for(int j=0;j<m;j++){
            if(arr[a][j]==1){
                current+=1;
            }
            else{
                current=0;
            }
            score=max(score,current);
        }
        scores[a]=score;
        int res=scores[0];
        for(int j=1;j<n;j++)res=max(res,scores[j]);
        cout<<res<<endl;
    }

    return 0;
}