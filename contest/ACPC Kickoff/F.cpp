#include<bits/stdc++.h>

#define aint(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef pair<int,int> ii;
typedef pair<int,int> pl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<int> vl;
typedef vector<vector<int>> vvl;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const int maxn = 1e7+2;
vector<int> p(maxn+1);

void nxtprime(){
    for(int i = 2; i <= maxn; ++i){
        if(!p[i]){
            for(int j = i; j <= maxn; j += i){
                if(!p[j]) p[j] = i;
            }
        }
    }
}

vector<int> primes(int x){
    vector<int> fac;
    while(x > 1){
        int pr = p[x];
        fac.push_back(pr);
        while(x % pr == 0) x /= pr;
    }
    return fac;
}

int main(){fast();
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    nxtprime();

    //graph and check bipartite
    int res=0;

    vector<vector<int>> index_prime(maxn+1);
    vector<vector<int>> g(n);
    
    for(int i = 0; i < n; ++i){
        for(int p : primes(arr[i])){
            auto &v = index_prime[p];
            v.push_back(i);
            if(v.size() > 2){
                cout << -1 << endl;
                return 0;
            }
            if(v.size() == 2){
                int u = v[0], w = v[1];
                g[u].push_back(w);
                g[w].push_back(u);
            }
        }
    }


    //now bicolor
    vi color(n,-1);
    for(int i=0;i<n;i++){
        if(color[i]  != -1)continue;
        color[i] = 0;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int current = q.front();
            q.pop();

            for(auto neighb : g[current]){
                if(color[neighb]==color[current])res=-1;
                if(color[neighb] != -1)continue;//already done
                color[neighb]  = 1 - color[current];
                q.push(neighb);
            }

            if(res==-1)break;
        }

    }

    if(res==-1)cout<<res<<endl;
    else {
        for (int i = 0; i < n; i++) {
            cout << color[i]+1 << (i + 1 < n ? ' ' : '\n');
        }
    }
    return 0;
}