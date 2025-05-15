//link : https://vjudge.net/problem/UVA-441
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
    int n;bool first=true;
    while(cin>>n){
        if(n==0)break;
        if(!first)cout<<endl;
        else first=false;
        vi arr(n);
        for(int &a:arr)cin>>a;
        sort(all(arr));
        for(int i=0;i<n-5;i++){
            for(int j=i+1;j<n-4;j++){
                for(int k=j+1;k<n-3;k++){
                    for(int i1=k+1;i1<n-2;i1++){
                        for(int j1=i1+1;j1<n-1;j1++){
                            for(int k1=j1+1;k1<n;k1++){
                                printf("%d %d %d %d %d %d\n",arr[i],arr[j],arr[k]
                                ,arr[i1],arr[j1],arr[k1]);
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
