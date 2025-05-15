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
int n;
vector<int> arr(10);
vector<int> sol;
void solve(int i,int n1,int n2,int n3){
    if(i==n){
        sol.push_back(max(n1,max(n2,n3)));
        return ;
    }

    solve(i+1,n1,n2+arr[i],n3);
    solve(i+1,n1+arr[i],n2,n3);
    solve(i+1,n1,n2,n3+arr[i]);
}

int main(){fast();

    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];

    solve(0,0,0,0);
    sort(all(sol));
    cout<<sol[0]<<endl;

    return 0;
}