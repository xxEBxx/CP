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



const int maxn = (int) 2 * 1e5 + 7;
const int mod = (int) 1e9 + 7;

int ask(int a) {
    cout<<"? "<<a<<endl;
    int val;cin>>val;
    return val;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        //if someone increases he is not the answer
        set<int> s;
        for (int i =1;i<=n;i++) {
            s.insert(i);
        }

        int start=1;
        vi given_start(n+1,0);
        while (s.size() > 1){

            for (auto elem : s) {
                if (given_start[elem]==0) {
                    start = elem;
                    given_start[elem]=1;
                    break;
                }
            }
            int last = ask(start);
            if (last==0) {
                s = {start};
                break;
            }
            if (s.find(start)!=s.end())s.erase(start);
            if (s.size()==1)break;

            for (int j = start; j < n+start-1; j++) {
                int i = j%n +1 ;
                int res = ask(i);
                if (last < res) {
                    if (s.find(i)!=s.end())
                        s.erase(i);
                    if (s.size()==1)break;
                }
                last = res;
            }
        }
        cout<<"! "<<*s.begin()<<endl;
        int res=0;cin>>res;
        if (res==0)
            return 0;
    }
}