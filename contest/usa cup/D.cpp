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
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
            a[i]=abs(a[i]);
            a[i]%=10;
        }

        vector<int> b(n);
        for(int i=0;i<n;i++){
            cin>>b[i];
        }

        vi generable(10,0);
        for(int i=0;i<n;i++){
            //for(int iii:generable)cout << iii << " ";
           // cout << endl;

            string letter="N";


            if(a[i] == b[i]) {
                letter= "Y";
            }
            else{
                for(int j=0;j<10;j++){
                    if(generable[j]==0)continue;
                    if((a[i] * j) %10 == b[i]){
                        letter = "Y";
                    }
                }
            }
            vi next;
            for(int j=0;j<10;j++){
                if(generable[j]==0)continue;
                next.push_back((a[i]*j) % 10);
            }
            next.push_back(a[i]);
            for(int oo:next)generable[oo] = 1;




            cout<<letter;
        }
        cout<<endl;


    }
    return 0;
}