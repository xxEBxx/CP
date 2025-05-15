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
    int t;cin>>t;
    while(t--){
        int n,k,q;cin>>n>>k>>q;
        vector<float> a(k+1),b(k+1);
        a[0]=0;
        b[0]=0;
        vector<float> v(k);
        //v(k) is the speed from a(k) to a(k+1)
        for(int i=1;i<1+k;i++){
            cin>>a[i];
        }
        for(int i=1;i<1+k;i++){
            cin>>b[i];
        }
        v[0]=a[1]/b[1];cout<<v[0]<<" ";
        for(int i=1;i<k;i++){
            v[i]=(a[i+1]-a[i])/(b[i+1]-b[i]);
            cout<<v[i]<<" ";
        }

        //cout<<"here q";
        for(int i=0;i<q;i++){
//we find index of element just smaller than d
            int d;cin>>d;
            cout<<"here is d"<<d<<endl;
            if(d <= a[1]){
                int res=d/v[0];
                cout<<res<<" ";
                continue;
            }
            int index= prev(upper_bound(a.begin(),a.end(),d))-a.begin();
            //cout<<"here is index for d"<<d<<" "<<index<<endl;
            cout<<(int)(b[index] + (d-a[index])/v[index]) <<" ";
        }
        cout<<endl;
    }
    return 0;
}