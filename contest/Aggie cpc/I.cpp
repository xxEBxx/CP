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
    int n,k;
    cin>>n>>k;
    vector<int> arr(n,0);
    for(int i=0;i<2*k;i++){
        int val;cin>>val;
        val--;
        arr[val]++;
    }
    multiset<int> elem;
    for(auto i : arr){
        elem.insert(i);
    }

    while(*(elem.begin()) != *(prev(elem.end()))){
        int a=*elem.begin();
        elem.erase(elem.begin());
        int b=*elem.begin();
        elem.erase(elem.begin());
        a++;
        b++;
        elem.insert(a);
        elem.insert(b);
    }
    cout<<*(elem.begin())<<endl;
    return 0;
}