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

struct node{
    int i,j,d;
};

int main(){fast();
    int n,m;cin>>n>>m;
    vector<string> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    vvi distance(n,vi(m,1e9));
    queue<node> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == 'E'){
                q.push({i,j,0});
            }
        }
    }

    while(!q.empty()){
        node head = q.front();
        q.pop();
        int i=head.i,j=head.j,d=head.d;

        if(j>0 && arr[i][j-1] == '.'){
            arr[i][j-1] = '>';
            q.push({i,j-1,1+d});
        }

        if(j<m-1 && arr[i][j+1] == '.'){
            arr[i][j+1] = '<';
            q.push({i,j+1,1+d});
        }

        if(i>0 && arr[i-1][j] == '.'){
            arr[i-1][j] = 'v';
            q.push({i-1,j,1+d});
        }

        if(i<n-1 && arr[i+1][j] == '.'){
            arr[i+1][j] = '^';
            q.push({i+1,j,1+d});
        }
    }

    for(int i=0;i<n;i++)
        cout<<arr[i]<<endl;


    return 0;
}