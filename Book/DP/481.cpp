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
int n;
vi arr,L(maxn, 0), L_id(maxn, 0),p(maxn,-1);
int res=0;
vi output;
void print_lis(int i){
    res++;
    output.push_back(arr[i]);
    if(p[i]==-1)return;
    else print_lis(p[i]);
}

int main(){fast();
    while(cin>>n){
        //if(n==0)break;
        arr.push_back(n);
    }
    n=arr.size();
    int k = 0, lis_end = 0;
    for (int i = 0; i < n; i++) {
        //cout<<"here is arr[i]"<<arr[i]<<endl;
        int pos = lower_bound(L.begin(), L.begin()+k, arr[i]) - L.begin();
        //cout<<"here is pos"<<pos<<" "<<L.size()-1<<" "<<k<<endl;
        L[pos] = arr[i];
        L_id[pos] = i;
        p[i] = pos ? L_id[pos-1] : -1;
        if (pos == k ) {
            k = pos+1;
            lis_end = i;
        }
        else if (pos==k-1)lis_end=i;
    }
    print_lis(lis_end);
    reverse(all(output));
    cout<<res<<endl<<"-"<<endl;
    for(int r:output)cout<<r<<endl;

    return 0;
}