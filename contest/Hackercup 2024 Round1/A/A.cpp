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
        int n;cin>>n;
        vector<double> open(1+n),close(1+n);
        for(int i=1;i<=n;i++){
            cin>>open[i]>>close[i];
        }
        double max_speed=(double)1e18,min_speed=1/close[1];
        if(open[1] != 0)
            max_speed=1/open[1];

        for(int i=2;i<=n;i++){
            min_speed=max(min_speed,i/close[i]);
            if(open[i] > (float)0)max_speed=min(max_speed,i/open[i]);
        }
        if(max_speed >= min_speed )
            if(min_speed <= 1e-6)
            cout<<min_speed<<endl;
        else
            cout<<-1<<endl;
    }
}

int main() {
    run_with_stack_size(main_, 1024 * 1024 * 1024); // run with a 1 GiB stack
    return 0;
}
