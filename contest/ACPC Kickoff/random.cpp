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

int main(){fast();
    int t;cin>>t;
    while(t--){
        int n,q;cin>>n>>q;
        vector<int> index(n+1),arr(n+1);
        for(int i=1;i<=n;i++){
            int val;cin>>val;
            index[val] = i;
            arr[i]=val;
        }


        for(int i=0 ; i<q ; i++){
            int l,r,k;
            cin>>l>>r>>k;
            int less=0,more=0,more_condition=0,less_condition=0;
            int mid=(l+r)/2;
            bool res = false;
            if(index[k] > r || index[k] < l)
                res=true;
            while(arr[mid] != k && (r-l) > 0 ){
                mid=(l+r)/2;
                if(mid < index[k] ){
                    if(arr[mid] > k){
                        less++;
                        less_condition++;
                    }
                    more_condition++;
                    l = mid+1;
                }
                else{
                    if(arr[mid] < k){
                        more++;
                        more_condition++;
                    }
                    less_condition++;
                    r = mid-1;
                }
            }

            if(more_condition > k-1 || less_condition > n-k || res)
                cout<<-1<<" ";
            else{
                cout<<max(more,less)*2<<" ";
            }

        }
        cout<<endl;

    }
    return 0;
}