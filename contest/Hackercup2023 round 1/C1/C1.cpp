
#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;

const int maxn=(int)1e6*4+7;
const int mod=(int)1e9+7;

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

void main_(){fast();
    int t,tt=0;cin>>t;
    int count[maxn];
    while(t--){tt++;
        cout<<"Case #"<<tt<<": ";
        int n;cin>>n;
        string s1;cin>>s1;
        string s="a"+s1;
        int q;cin>>q;
        for(int i=1;i<=n;i++) {
            if (s[i] == '1')
                count[i] = 1;
            else count[i]=0;
        }
        map<int,int> elems;
        for(int i=0;i<q;i++){
            int val;cin>>val;
            elems[val]++;
        }

        for(auto val:elems){
            if(val.second%2==0)continue;
            for(int k = val.f ; k <=n ; k += val.f){
                count[k] = 1-count[k];
            }
        }

        int res=0;
        for(int i=1;i<=n;i++){
            if(count[i]==0)continue;
            res++;
            for(int k=i;k<=n;k+=i)
                count[k]=1-count[k];
        }
        cout<<res<<endl;

    }
}


int main() {
    run_with_stack_size(main_, 1024 * 1024 * 1024); // run with a 1 GiB stack
    return 0;
}