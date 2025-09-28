
#include <bits/stdc++.h>


using namespace std;

const int N = 1e6 + 10, ALPHABET = 128;

map<char, int> child[N];
int fail[N], nxt[N], pid[N], ndCnt;

int addNode() {
    child[ndCnt].clear();
    pid[ndCnt] = -1;
    fail[ndCnt] = nxt[ndCnt] = -1;
    return ndCnt++;
}

void init() {
    ndCnt = 0;
    addNode();
}

int insert(const char *str, int id) {
    int u;
    for (u = 0; *str; ++str) {
        int &v = child[u].emplace(*str, -1).first->second;
        if (!~v)v = addNode();
        u = v;
    }
    if(!~pid[u])
        pid[u] = id;
    return pid[u];
}

int getFail(char c, int w) {
    while (1){
        auto it=child[w].find(c);
        if(it != child[w].end())
            return it->second;
        w=fail[w];
    }
}

void buildFail() {
    queue<int> q;
    for(int c=0;c<ALPHABET;++c){
        int &v = child[0].emplace(c,0).first->second;
        if(v)
            q.push(v),fail[v]=nxt[v]=0;
    }
    while (q.size()){
        int u = q.front();
        q.pop();
        for (auto [c, v]: child[u]){
            fail[v]=nxt[v]=getFail(c, fail[u]);
            q.push(v);
        }

    }
}

void print() {
    for (int u = 0; u < ndCnt; ++u)
        for (auto [c, v]: child[u])
            if(u!=v)
            printf("%d,%d,%d %d,%d,%d %c\n", u, pid[u],fail[u], v, pid[v],fail[v], c);

}

int getNxt(int u){
    if(!u) return u;
    return ~pid[nxt[u]]?nxt[u]:nxt[u]= getNxt(nxt[u]);
}

vector<vector<int>> match(const char *str,const vector<int> &len){
    vector<vector<int>> ret(len.size());
    for(int u=0,i=0;str[i];++i){
        u=getFail(str[i], u);
        for(int v=u;v;v=getNxt(v))
            if(~pid[v]){
                int id = pid[v];
                ret[id].push_back(i - len[id] + 1);
            }
    }
    return ret;

}

char str[N],pat[N];

int main() {

    init();
    vector<int> len,id,freq;
    int n;
    scanf("%s%d", str, &n);
    for(int i=0;i<n;++i){
        int a;cin>>a;
        freq.push_back(a);

        scanf("%s", pat);
        id.push_back(insert(pat, i));
        len.push_back(strlen(pat));
    }
    buildFail();
    auto ret = match(str, len);

    for(int i=0;i<n;i++) {
        int res=1e9;
        int limit = ret[i].size() - freq[i];
        for (int j=0;  j <= limit ; j++) {
            res = min(res,ret[i][j+freq[i]-1]+len[i] - ret[i][j]);
        }
        if (res == 1e9)
            cout<<-1<<endl;
        else
            cout<<res<<endl;
    }

    return 0;
}
