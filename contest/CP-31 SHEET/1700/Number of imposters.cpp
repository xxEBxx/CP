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

struct edge{
    int a,b,color;
};
vector<vector<pair<int,int>>> g;




int main(){fast();
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        g.assign(n+1,vector<pair<int,int>> () );

        for(int i=0;i<k;i++){
            int a,b,color;
            string s;
            cin>>a>>b>>s;
            if(s=="imposter")
                color=1;
            else
                color=0;

            g[a].push_back({b,color});
            g[b].push_back({a,color});
        }

        vector<int> color(n+1,-1);
        int error=0;
        int res=0;
        for(int i=1;i<=n;i++){
            if(error)break;
            if(color[i] > -1)continue;
            queue<int> q;
            q.push(i);
            color[i]=0;
            int red=1,blue=0;

            while(!q.empty()){
                if(error)break;
                int head=q.front();
                q.pop();

                for(auto child : g[head]){
                    int next_color = color[head];
                    if(child.second==1)next_color=1-next_color;

                    if(color[child.f] == -1) {
                        color[child.f] = next_color;
                        q.push(child.f);
                        if(next_color==0)
                            red++;
                        else
                            blue++;
                    }
                    else if(color[child.f] != next_color){
                        error=1;
                    }

                }

            }

            res+=max(red,blue);
        }
        if(error)
            cout<<-1<<endl;
        else
            cout<<res<<endl;


    }
    return 0;
}