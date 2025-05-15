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

const int MAXN = 260005;

string process(string s){
    string res;
    string curr;
    int n=s.size();
    int i=0;
    for(;i<n;i++){
        int dec=0;
        while(i<n && s[i]!='.' && s[i]!='/'){
            dec *= 10;
            dec += s[i]-'0';
            i++;
        }
        string loc;
        while(dec>0){
            if(dec&1)loc.push_back('1');
            else loc.push_back('0');
            dec>>=1;
        }
        while(loc.size()<8)
            loc.push_back('0');
        reverse(all(loc));
        res += loc;
        if(s[i]=='/')
            break;
    }
    i++;
    int len=32;
    if(i==n-2){
        len = 10*(s[i]-'0')+s[i+1]-'0';
    }
    else if(i==n-1){
        len = s[i]-'0';
    }
    string ans;
    for(int j=0;j<len;j++)
        ans += res[j];

    return ans;
}

struct Trie {
    static const int ALPHA = 2;
    struct Node {
        int next[ALPHA];
        int index ;
        Node() {
            memset(next, -1, sizeof(next));
            index = -1;
        }
    };
    vector<Node> nodes;
    Trie() { nodes.emplace_back(); }

    void insert(const string& s,int ind) {
        int v = 0;
        for (char ch : s) {
            int c = ch - '0';
            if (nodes[v].next[c] == -1) {
                nodes[v].next[c] = nodes.size();
                nodes.emplace_back();
            }
            v = nodes[v].next[c];
        }
        nodes[v].index= ind;
    }

    int search(const string& s) {
        int v = 0;
        int res = nodes[0].index;

        for (char ch : s) {
            int c = ch - '0';
            if (nodes[v].next[c] == -1) {return res;}
            v = nodes[v].next[c];
            if(nodes[v].index != -1)
                res = nodes[v].index;
        }
        return res;
    }
};



int main(){fast();
    //cout<<process("192.1.1.1")<<endl;
    //cout<<process("192.1.1.1/31")<<endl;

    int n,m;
    cin>>n>>m;
    Trie tr;
    for(int i= 0;i<n;i++){
        string s;cin>>s;
        tr.insert(process(s),i+1);
    }
    for(int i= 0;i<m;i++){
        string s;cin>>s;
        s = process(s);
        cout<<tr.search(s)<<endl;
    }

    return 0;
}