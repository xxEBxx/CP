#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef pair<ll,ll> pl;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;

const ll maxn=(ll)1e6+7;
const ll p=(ll)1e9+7;

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

ll dp[19][2][10],m,n;
string word;

ll solve(ll i,ll lower,ll before,ll remainder){
    //we work with word,and n;
    if(i==n){
        return (remainder%m)==0;
    }

    if(dp[i][lower][before] != -1)
        return dp[i][lower][before];
    ll high;
    if(lower)
        high=9;
    else
        high = word[i]-'0';
    ll res=0;
    
    if(i==0){
        for(ll index=1 ; index < high ; index++)
            res += solve(1,1,index,index%m);
        res+=solve(1,0,high,high % m);
    }
    else if(i == n/2){
        for (ll index = before + 1 ;index <= high; index++) {
            ll nl=lower;
            if(index < high)
                nl=1;
            res += solve(i+1,nl,index,(remainder*10+index)%m);
        }
    }

    else if(i > n/2){
        int remove_one=0;
        if(i==n/2+1)remove_one++;
        for (ll index = min(high,before -remove_one);index >= 1; index--) {
            ll nl=lower;
            if(index < high)
                nl=1;
            res += solve(i+1,nl,index,(remainder*10+index)%m);
        }
    }

    else if(i < n/2){
        for (ll index = before ;index <= high; index++) {
            ll nl=lower;
            if(index < high)
                nl=1;
            res += solve(i+1,nl,index,(remainder*10+index)%m);
        }
    }

    return dp[i][lower][before]=res;
}

ll check(string s) {
    ll l = s.length();
    if(l%2 == 0)
        return 0;
    bool tr =true;
    for(ll i=1;i<l/2;i++) {
        if(s[i] < s[i-1]) {
            tr =false;
            break;
        }
    }
    for(ll i=l/2;i<l-1;i++) {
        if(s[i] < s[i+1]) {
            tr =false;
            break;
        }
    }
    char c = s[l/2];
    for(ll i=0;i<l;i++) {
        if(s[i]=='0')
            tr= false;
        if(i != l/2) {
            if(s[i] == c) {
                tr= false;
                break;
            }
        }
    }
    return tr;
}

void main_(){fast();
    ll t,tt=0;cin>>t;
    while(t--){tt++;
        cout<<"Case #"<<tt<<": ";
        string a,b;
        cin>>a>>b>>m;
        ll number_a = 0,number_b = 0;
//we will check each size one time
        word=a;
        for(ll i=1;i<a.size();i+=2){
            n=i;
            memset(dp,-1,sizeof(dp));
            number_a += solve(0,1,0,0);
        }
        n=a.size();
        if(n&1){
            memset(dp, -1, sizeof(dp));
            number_a += solve(0,0,0,0);
        }

        word=b;
        for(ll i=1 ; i<b.size() ; i+=2){
            n=i;
            memset(dp,-1,sizeof(dp));
            number_b += solve(0,1,0,0);
        }
        n=b.size();
        if(n&1){
            memset(dp, -1, sizeof(dp));
            number_b += solve(0,0,0,0);
        }
        cout<<number_b - number_a + check(a)<<endl;
    }
}

int main() {
    run_with_stack_size(main_, 1024 * 1024 * 1024); // run with a 1 GiB stack
    return 0;
}
