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

using namespace std;
const int MAX_A = 1e7 + 5;
vector<int> prime(MAX_A+1,1),res(MAX_A+1,0);

void  siev_of_eratosthenes() {
    prime[1]=0;
    for (int i = 2; i <= MAX_A; ++i) {
        if (prime[i]==1) { // i is a prime number
            for (int multiple = i+i; multiple <= MAX_A; multiple += i) {
                prime[multiple]=0;
            }
        }
    }
}

void main_(){fast();
    int t;cin>>t;
    int ans=2;
    siev_of_eratosthenes();
    //cout<<prime[5]<<prime[7]<<endl;
    for(int i=7;i <= MAX_A - 1;i++){
        if(prime[i]==1 && prime[i-2]==1) {
            ans++;
        }
        res[i]=ans;
    }
    int tt=0;
    while(t--){tt++;
        cout<<"Case #"<<tt<<": ";
        int n;cin>>n;
        if(n<5){
            cout<<0;
            if(t>0)cout<<endl;
            continue;
        }
        if(n<7){
            cout<<2;
            if(t>0)cout<<endl;
            continue;
        }
        cout<<res[n];
        if(t>0)cout<<endl;
    }
}

int main() {
    run_with_stack_size(main_, 1024 * 1024 * 1024); // run with a 1 GiB stack
    return 0;
}
