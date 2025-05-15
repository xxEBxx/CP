#include<bits/stdc++.h>
#include <iostream>
#include <fstream>

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
#define L(i) (i<<1)
#define R(i) ((i<<1)+1)
#define M(i,j) ((i+j)>>1)

int n,arr[maxn];
vvi st(maxn*3,vi (26,0));

vi merge(vi a,vi b){
    vi res (26,0);
    for(int i=0;i<26;i++)
        res[i]=a[i]+b[i];
    return res;
}

void build(int id,int l,int r){
    if(l==r) {
        vi res (26,0);
        res[s[l]-'a']++;
        return ;
    }
    int mid=M(l,r);
    build(L(id),l,mid);
    build(R(id),mid+1,r);
    st[id]=merge(st[L(id)],st[R(id)]);
}

void update(int id,int l,int r,int index,int val){
    if(index<l || index>r)
        return;
    if(l==r){
        arr[index] = val;

    }
}


void main_() {
    fast();
    int t, tt = 0;
    cin >> t;
    while (t--) {
        tt++;
        cout << "Case #" << tt << ": ";
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        build(1,n,n);
    }
}

int main() {
    run_with_stack_size(main_, 1024 * 1024 * 1024); // run with a 1 GiB stack
    return 0;
}
