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

int main(){fast();
    int t,tt=0;cin>>t;
    while(t--){tt++;
        int n;cin>>n;
        cout<<"Case #"<<tt<<": ";
        vi divisors;
        if(n > (1<<20)){
            cout<<-1<<endl;
            continue;
        }
        int sum=0;
        while(n>1){
            for(int i=2;i<=n;i++){
                if(n%i == 0){
                    divisors.push_back(i);
                    sum += i;
                    n /= i;
                    break;
                }
            }
        }
        if(sum > 41)
        {cout<<-1<<endl;continue;}
        while(sum < 41){
            sum++;
            divisors.push_back(1);
        }
        cout<<divisors.size()<<" ";
        for(int elem:divisors)
            cout<<elem<<" ";
        cout<<endl;
    }
    return 0;
}