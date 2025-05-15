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
    while(t--){tt++;
        cout<<"Case #"<<tt<<": ";
        string s;
        cin>>s;
        s = "a"+s;
        int n=s.size();
        vvi ps(n+1,vi(26,0));
        for(int i=1;i<=n;i++){
            for(int j=0;j<26;j++){
                ps[i][j]=ps[i-1][j];
                if(j == s[i]-'a')
                    ps[i][j]++;
            }
        }
        int q;cin>>q;
        int res=0;
        for(int i=0;i<q;i++){
            int a,b;cin>>a>>b;
            if((b-a)&1)continue;
            int middle=(b+a)/2;
            //middle before ;
            int diff=0;
            for(int j=0;j<26;j++){
                if((ps[middle][j] - ps[a-1][j]) != (ps[b][j] -ps[middle][j])){
                    if(diff==1) {
                        diff = 2;
                        break;
                    }
                    diff=1;
                }
            }
            if(diff==1){
                res++;
                continue;
            }
            //now we try dividing on middle+1
            diff=0;
            for(int j=0;j<26;j++){
                if((ps[middle-1][j] - ps[a-1][j]) != (ps[b][j] - ps[middle-1][j])){
                    if(diff==1) {
                        diff = 2;
                        break;
                    }
                    diff=1;
                }
            }
            if(diff==1)
                res++;

        }
        cout<<res;
        if(t>0) cout<<endl;
    }

}

int main() {
    run_with_stack_size(main_, 1024 * 1024 * 1024); // run with a 1 GiB stack
    return 0;
}

