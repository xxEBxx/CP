
#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vl;
typedef vector<vector<ll> > vvl;

void fast() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const int maxn = (int) 3 * 1e5 + 7;
const int mod = (int) 1e9 + 7;


extern struct node *const EMPTY;
const int N = (int) 3 * 1e5 + 7;
struct node{
    vi count;
    node *left, *right;
    node(): left(this), right(this) {
        count.assign(26,0);
    }
    node(vi val , node *l=EMPTY, node *r=EMPTY):  left(l),right(r) {
        count=val;
    }
};
node *const EMPTY= new node();
node *insert(int v,int letter,int updateval,node *cur,int ns=0,int ne=1e9){
    if(v>ne || v<ns) return cur;
    if(ns==ne) {
        vi res = cur->count ;
        res[letter]+= updateval;
        return new node(res);
    }
    int mid = ns + (ne - ns) / 2;
    node *left = insert(v,letter,updateval, cur->left, ns, mid);
    node *right = insert(v,letter,updateval, cur->right, mid + 1, ne);
    vi res(26,0);
    for (int i=0;i<26;i++)
        res[i]=right->count[i]+left->count[i];
    return new node(res, left, right);
}
node *roots[N]={EMPTY};

int sum(int l,int r,int letter, node *se, int ns=0, int ne=1e9) {
    //gives the kth from the left
    if (l>ne || ns>r)return 0;
    if (l<=ns && ne<=r)
        return se->count[letter];

    int mid = ns + (ne - ns) / 2;

    return sum(l,r,letter, se->left,ns,mid)
        +sum(l,r,letter, se->right, mid + 1, ne);
}

int query_right(int l,int r,int k,int letter, node *se, int ns=0, int ne=1e9) {
    //gives the kth from the left
    if(ns == ne) return ns;
    int rightSum = sum(max(l,ns),min(ne,r),letter,se->right) ; ;
    int mid = ns + (ne - ns) / 2;
    if(rightSum >= k)
        return query_right(l,r,k, letter,se->right,  ns, mid);
    return query_right(l,r,k - rightSum,letter, se->left, mid + 1, ne
    );
}

int query_left(int l,int r,int k,int letter, node *se, int ns=0, int ne=1e9) {
    //gives the kth from the left
    if(ns == ne) return ns;
    int leftSum = sum(max(l,ns),min(ne,r),letter,se->left) ;
    int mid = ns + (ne - ns) / 2;
    if(leftSum >= k)
        return query_left(l,r,k, letter,se->left, ns, mid);
    return query_left(l,r,k - leftSum,letter, se->right, mid + 1, ne
    );
}



string s;

int main() {
    cin>>s;
    int n;
    cin>>n;

    for (int i=0;i<s.size();i++ ) {
        roots[0] = insert(i,s[i]-'a',1,roots[0]);
    }
    int ver=0;
    while (n--) {
        int a;
        cin>>a;
        if (a==1) {
            int i;char x;
            cin>>i>>x;
            ver++;
            roots[ver] = insert(i,s[i]-'a',-1,roots[ver-1]);
            roots[ver] = insert(i,x-'a',1,roots[ver]);
            s[i]=x;
        }
        else {
            int v,l,r,k;
            char c,d;
            cin>>v>>l>>r>>k>>c>>d;
            int index_c = query_left(l,r,k,c-'a',roots[v]);

            int index_c1 = query_left(l,r,k+1,c-'a',roots[v]);
            int index_d = query_right(l,r,k,d-'a',roots[v]);

            cout<<max(0,min(index_d,index_c1) - index_c +1)<<endl;
        }
    }
    return 0;
}

