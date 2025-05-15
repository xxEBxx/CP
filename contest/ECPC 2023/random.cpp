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
    int n,m;cin>>n>>m;
    vector<set<int>> arr(n);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int val;cin>>val;
            arr[i].insert(val);
        }
    }
    vector<pair<int,vi>> elems;
    int ii=0;
    for(auto elem :arr[0]) {
        elems.push_back({elem, {ii}});
        ii++;
    }
    for(auto upper:arr.begin()+1){
        vector<pair<int,vi>> next;
        for (auto elem :elems){
            ii=0;
            for(auto lower : upper){
                vector<int> next_one=elem.s;
                next_one.push_back(ii);
                ii++;
                next.push_back({elem.f^lower,next_one});
            }
        }
        elems=next;
    }
    for(auto elem:elems){
        if(elem.f!=0){
            cout<<"TAK"<<endl;
            for(auto index:elem.s)
                cout<<index+1<<" ";
            return 0;
        }
    }
    cout<<"NIE"<<endl;
    return 0;
}