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
int countAndMerge(vector<int>& arr, int l, int m, int r) {

    int n1 = m - l + 1, n2 = r - m;

    vector<int> left(n1), right(n2);
    for (int i = 0; i < n1; i++)
        left[i] = arr[i + l];
    for (int j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];

    int res = 0;
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {

        if (left[i] <= right[j])
            arr[k++] = left[i++];

        else {
            arr[k++] = right[j++];
            res += (n1 - i);
        }
    }

    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];

    return res;
}

int countInv(vector<int>& arr, int l, int r){
    int res = 0;
    if (l < r) {
        int m = (r + l) / 2;

        res += countInv(arr, l, m);
        res += countInv(arr, m + 1, r);

        res += countAndMerge(arr, l, m, r);
    }
    return res;
}
//        int res= countInv(b,0,n-1);


int main(){fast();
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n),b(n);
        multiset<int> aa,bb;
        for(int i=0;i<n;i++){
            cin>>a[i];
            aa.insert(a[i]);
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
            bb.insert(b[i]);
        }

        if(aa!=bb){
            cout<<"NO"<<endl;
            continue;
        }

        unordered_map<int,vi> m;
        for(int i=0;i<n;i++){
            m[a[i]].push_back(i+1);
        }
        for(int i=0;i<n;i++){
            b[i] = m[b[i]][0];
            m[b[i]].erase(m[b[i]].begin());
            //cout<<b[i]<<" ";
        }
        int res= countInv(b,0,n-1);
        //cout<<res<<endl;
        if(res&1)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    return 0;
}