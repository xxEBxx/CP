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
const int p=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}
int n,arr[maxn],lp[4*maxn];

#define L(i) (i<<1)
#define R(i) ((i<<1)+1)
#define M(i,j) ((i+j)>>2)

struct node{
    int max_elem;
    int max_index;
    int min_elem;
    int min_index;
};
node st[4*maxn];

void run_with_stack_size(void (*func)(), size_t stsize) {
    char *stack, *send;
    stack=(char *)malloc(stsize);
    send=stack+stsize-16;
    send=(char *)((uintptr_t)send/16*16);
    asm volatile(
            "mov %%rsp, (%0)\n"
            "mov %0, %%rsp\n"
            :
            : "r" (send));
    func();
    asm volatile(
            "mov (%0), %%rsp\n"
            :
            : "r" (send));
    free(stack);
}

void change(int id){
    st[id] = {p-st[id].min_elem,p-st[id].min_elem};
}

void update(int id,int l,int r,int a,int b){
    if(a > r || b < l)
        return;
    if(l==r)
        change(id);

    if(a<=l && r<=b) {
        change(id);
    }

    int mid=M(l,r);
    update(L(id),l,mid,a,b);
    update(R(id),mid+1,r,a,b);

    st[id]={min(st[L(id)].f,st[R(id)].f),max(st[L(id)].s,st[R(id)].s)};
}

int query(int id,int l,int r,int a,int b){
    if(l==r){
        if(lp[id]==1)return p - st[id].f;//inverse of min
        return st[id].s;//max
    }

    if(lp[id]==1){
        change(id);
        lp[R(id)]=1;
        lp[L(id)]=1;
        lp[id]=0;
    }

    int mid=M(l,r);
    return max(query(L(id),l,mid,a,b),query(R(id),mid+1,r,a,b));

}

void build(int id,int l,int r){
    if(l==r) {
        st[id] = {arr[l], l,arr[l],l};
        return ;
    }

    int mid=M(l,r);
    build(L(id),l,mid);
    build(R(id),mid+1,r);

    int min_index=st[id].min_index,mxan


    st[id]={min(st[L(id)].f,st[R(id)].f),max(st[L(id)].s,st[R(id)].s)};
}

void main_(){fast();
    int t;cin>>t;
    while(t--){
        memset(lp,0,sizeof(lp));
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        int q;cin>>q;
        while(q--){

        }
    }
}



int main() {
    run_with_stack_size(main_, 1024 * 1024 * 1024); // run with a 1 GiB stack
    return 0;
}
