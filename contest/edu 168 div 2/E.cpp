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

const int maxn=(int)2*1e5+7;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int main(){fast();
        int n,q;cin>>n>>q;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int count[maxn];
        memset(count,0,sizeof(count));
        for(int i=0;i<q;i++){
            int index,coeff;cin>>index>>coeff;
            index--;
            int level=1+count[coeff]/coeff;
            cout<<count<<" "<<level<<" "<<arr[index]<<endl;
            if(level > arr[index]){
                cout<<"NO"<<endl;
            }
            else {
                cout<<"YES"<<endl;
                count[coeff]++;
            }
        }

    return 0;
}