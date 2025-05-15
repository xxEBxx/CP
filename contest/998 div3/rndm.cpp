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
        vi deg(n+1,0);
        map<int,vi> g;
        for(int i=0;i<n-1;i++){
            int a,b;
            cin>>a>>b;
            deg[a]++;
            deg[b]++;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        int max_elem=0,index_max=0;
        map<int,vi> count_deg;
        for(int i=1;i<=n;i++){
            count_deg[deg[i]].push_back(i);
            if (deg[i] > max_elem) {
                max_elem = deg[i];
                index_max = i;
            }
        }
        if(count_deg[max_elem].size()>2){
            cout<<2*max_elem-1<<endl;
        }
        else if(count_deg[max_elem].size()==2){
            //check if they are connected
            int a=count_deg[max_elem][0],b=count_deg[max_elem][1];
            bool connected=false;
            for(auto elem:g[a]){
                if(elem==b){
                    connected=true;
                    break;
                }
            }
            if(connected){
                cout<<2*max_elem-2<<endl;
            }
            else{
                cout<<2*max_elem-1<<endl;
            }
        }
        else{
            //find one of the second highest that isnt a neighbour
            int res=max_elem;
            deg[index_max]=0;
            max_elem=0;
            for(int i=1;i<=n;i++){
                if (deg[i] > max_elem) {
                    max_elem = deg[i];
                }
            }
            int second_score=max_elem-2;
            sort(all(g[index_max]));
            for(int i=1;i<=n;i++){
                if(deg[i]==max_elem){
                    bool i_neighbour = binary_search(
                            g[index_max].begin(),
                            g[index_max].end(),
                            i
                    );
                    if(!i_neighbour){
                        second_score=max_elem-1;
                        break;
                    }
                }
            }
            cout<<res+second_score<<endl;
        }
    }
    return 0;
}