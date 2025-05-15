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

vi tr(vi a,int index,int val){
    int n=a.size()+1;
    vi res(n);
    res[index] = val;
    for(int i = index-1;i>=0;i--){
        res[i] = res[i+1]^a[i];
    }
    for(int i = index+1;i<n;i++){
        res[i] = a[i-1] ^ res[i-1];
    }
    bool valid = true;
    vi visited(n,0);
    for(int i=0;i<n;i++){
        if( res[i]>=n || visited[res[i]] == 1){
            valid = false;
            break;
        }
        visited[res[i]] = 1;
    }
    if(!valid){
        for(int i=0;i<n;i++){
            res[i]=-1;
        }
    }
    return res;
}

int main(){fast();
    int n;cin>>n;
    vi b(n),a(n-1);
    int max_elem = -1 , max_index;
    for(int i=0;i<n-1;i++){
        cin>>a[i];
        if(a[i]>max_elem){
            max_index = i;
            max_elem = a[i];
        }
    }
    for(int i=26;i>=0;i--){
        if((max_elem>>i)&1){
            vi res = tr(a,max_index,(1<<i));
            if(res[0] != -1){
                for(int j=0;j<n;j++)
                    cout<<res[j]<<" ";
                return 0;
            }
        }
    }

    return 0;
}