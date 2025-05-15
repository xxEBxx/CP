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
        int n;cin>>n;
        vector<int> arr(n);
        int index_max=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]==n){
                index_max=i;
            }
        }
        vector<int> paire,impaire;
        for(int i=0;i<n/2;i++){
            paire.push_back(arr[2*i]);
            impaire.push_back(arr[2*i+1]);
        }
        map<int,int> m;
        sort(all(impaire));
        sort(all(paire));

        if(!(index_max&1)){
            int i=0;
            for(int k:paire){
                m[k]=n-i;
                i++;
            }
            i=0;
            for(int k:impaire){
                m[k]=n/2-i;
                i++;
            }
        }
        else{
            int i=0;
            for(int k:paire){
                m[k]=n/2-i;
                i++;
            }
            i=0;
            for(int k:impaire){
                m[k]=n-i;
                i++;
            }
        }
        for(int k:arr){
            cout<<m[k]<<" ";
        }
        cout<<endl;
    }
    return 0;
}