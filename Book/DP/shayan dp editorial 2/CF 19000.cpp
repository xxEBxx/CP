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
    int n,k;cin>>n>>k;
    vvi arr(k,vi(n,0));
    for(int i=0;i<k;i++){
        for(int j=0;j<n;j++) {
            cin >> arr[i][j]; }
    }

    vvi greater(n+1,vi(n+1,1));
//greater[i][j] means can we put i before j in every array
//we will make 0's based on every array of the 5
    for(int i=0;i<k;i++){

        for(int j=0;j<n;j++){
            for(int l=j+1;l<n;l++){
                greater[arr[i][l]][arr[i][j]]=0;
            }
        }
    }

    vi lis(n,1);
    for(int i=1;i<n;i++){
        //we will follow first array for referenece
        for(int j=0;j<i;j++){
            if(greater[arr[0][j]][arr[0][i]]){
                lis[i]=max(lis[i],1+lis[j]);
            }
        }
    }
    //cout<<greater[2][3]<<endl;
    int res=1;
    for(int i=0;i<n;i++)res=max(res,lis[i]);
    cout<<res<<endl;
    return 0;
}