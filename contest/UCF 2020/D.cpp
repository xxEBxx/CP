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

struct obj{int n,l,r;};

int b;
bool comp(obj x, obj y) {
    if (x.l / b == y.l / b)
        return x.r < y.r;
    return x.l / b < y.l / b;
}

int main(){fast();
        int n;cin>>n;
        b = sqrt(n);
        vector<int> arr(n);

        unordered_map<int,pair<int,int>> first_last;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        unordered_map<int,int> current1;
        for(int i=0;i<n;i++){
            current1[arr[i]]++;
            if(current1[arr[i]] == 1){
                first_last[arr[i]] = {i,i};
            }
            else if(current1[arr[i]] > 1){
                first_last[arr[i]] = {first_last[arr[i]].f,i};
            }
        }

        vector<obj> nodes;
        for(auto elem : first_last){
            obj node = {elem.f,elem.s.f,elem.s.s};
            nodes.push_back(node);
        }

        sort(all(nodes),comp);
        int i = -1 , j = -1;
        unordered_map<int,set<int>> count;
        set<int> distinct ;
        int res = n;
        for(auto elem : nodes){
            int l = elem.l,r=elem.r;
            while (j < r) {
                j++;
                distinct.insert(arr[j]);
            }
            while (i > l) {
                i--;
                distinct.insert(arr[i]);
            }
            while (j > r) {
                distinct.erase(arr[j]);
                j--;
            }
            while (i < l) {
                distinct.erase(arr[i]);
                i++;
            }
            int

            res = min(res,(int)distinct.size());
        }

        cout<<res<<endl;


    return 0;
}