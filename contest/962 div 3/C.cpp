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
        int n,q;cin>>n>>q;
        map<char,vi> a_ind,b_ind;
        string a,b;cin>>a>>b;

        for(int i=0;i<n;i++){
            a_ind[a[i]].push_back(i+1);
        }
        for(int i=0;i<n;i++){
            b_ind[b[i]].push_back(i+1);
        }
        
        for(int i=0;i<q;i++){
            int from ,to;cin>>from>>to;
            int res=0;
            for(int cc=0;cc<26;cc++){
//we need to compute number of a between from to
                char letter='a'+cc;
                //cout<<letter<<endl;


                int count_a=0;
                if(!a_ind[letter].empty())count_a= upper_bound(a_ind[letter].begin(),a_ind[letter].end(),to)-lower_bound(a_ind[letter].begin(),a_ind[letter].end(),from);

                int count_b=0;
                if(!b_ind[letter].empty())count_b= upper_bound(b_ind[letter].begin(),b_ind[letter].end(),to)-lower_bound(b_ind[letter].begin(),b_ind[letter].end(),from);

                //cout<<letter<<" "<<count_a<<" "<<count_b<<endl;
                res += abs(count_a-count_b);
                //cout<<res<<endl;
            }
            cout<<res/2<<endl;
        }
    }
    return 0;
}


