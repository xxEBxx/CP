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

#define L(i) (i<<1)
#define R(i) (i<<1)+1
#define M(i,j) ((i+j)>>1)
ll sz;

ll  n,b;
struct obj{
    ll first,second,i;
};
bool comp(obj x,obj y) {
    if (x.first / b == y.first / b)
        return x.second < y.second;
    return x.first / b < y.first / b;
}


int main(){fast();
    cin>>n;
    b = (ll)sqrt(n);
    vector<int> arr(n);
    ll a,aa;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<obj> queries;
    int q;cin >> q;
    for(int i=0;i<q;i++){
        cin>>a>>aa;
        a--;aa--;
        queries.push_back({a,aa,i});
    }
    sort(all(queries),comp);

    int i = 0;
    int j = 0;
    multiset<int> sss;
    multiset<int> distances;
    sss.insert(arr[0]);
    vector<int> answers(q);
    for (auto& elem : queries) {
        ll l = elem.first, r = elem.second;

        while (j < r) {
            cout << "yes"<<endl;
            j++;
            auto position = sss.insert(arr[j]);
            auto next_elem = next(position);
            auto prev_it = prev(position);
            if(next_elem == sss.end()){
                distances.insert(arr[j] - *prev_it);
            }
            else if(position == sss.begin()){
                distances.insert( *next_elem - arr[j]);
            }
            else{
                distances.erase(*next_elem - *prev_it);
                distances.insert(arr[j] - *prev_it);
                distances.insert(*next_elem - arr[j]);

            }

        }
        for(auto elem : sss)cout<<elem<<" ";cout <<endl;
        for(auto elem : distances)cout<<elem<<" ";cout <<endl;

        while (i > l) {
            i--;
            auto position = sss.insert(arr[i]);
            auto next_elem = next(position);
            auto prev_it = prev(position);
            if(next_elem == sss.end()){
                distances.insert(arr[i] - *prev_it);
            }
            else if(position == sss.begin()){
                distances.insert( *next_elem - arr[i]);
            }
            else{
                distances.erase(*next_elem - *prev_it);
                distances.insert(arr[i] - *prev_it);
                distances.insert(*next_elem - arr[i]);

            }

        }

        while (j > r) {
            auto position = sss.lower_bound(arr[j]);
            auto next_elem = next(position);
            auto prev_it = prev(position);
            if(next_elem == sss.end()){
                distances.erase(arr[j] - *prev_it);
            }
            else if(position == sss.begin()){
                distances.erase( *next_elem - arr[j]);
            }
            else{

                distances.insert(*next_elem - *prev_it);
                distances.erase(arr[j] - *prev_it);
                distances.erase(*next_elem - arr[j]);

            }
            sss.erase(arr[j]);



            j--;
        }
        while (i < l) {
            cout << "no"<<endl;
            auto position = sss.lower_bound(arr[i]);
            auto next_elem = next(position);
            auto prev_it = prev(position);
            if(next_elem == sss.end()){
                distances.erase(arr[i] - *prev_it);
            }
            else if(position == sss.begin()){
                distances.erase( *next_elem - arr[i]);
            }
            else{

                distances.insert(*next_elem - *prev_it);
                distances.erase(arr[i] - *prev_it);
                distances.erase(*next_elem - arr[i]);

            }
            sss.erase(arr[i]);

            i++;
        }
        for(auto elem : sss)cout<<elem<<" ";cout <<endl;
        for(auto elem : distances)cout<<elem<<" ";cout <<endl;


        answers[elem.i]=*distances.begin();

    }
    for(auto elem : answers)
        cout<<elem<<endl;

    return 0;
}