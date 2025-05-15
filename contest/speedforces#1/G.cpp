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
    int n;cin>>n;
    int arr[2],count=0;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            if(count==1 && i%arr[0]==0) {
                //cout<<i<<" "<<arr[0]<<endl;
                arr[1]=i/arr[0];
                count++;
                break;
            }
            arr[count]=i;
            count++;
        }
        if(count==2)break;
    }

    if(count==0)cout<<1<<endl<<0<<endl;
    if(count==1)cout<<2;
    if(count==2){
        cout<<1<<endl<<arr[0]*arr[1];
    }
    return 0;
}