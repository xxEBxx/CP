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
        int n,m;
        cin >> n >> m;
        vector<int> arr(m);
        for(int i=0;i<m;i++)
            cin >> arr[i];
        int e = arr[0];
        int count = e-1;
        vector<int> visited(n+1,0);
        for(int i=1;i<m;i++){
            int a = arr[i];
            visited[a] = 1;
            if(a < e)
                count--;
        }
        if(count == 0){
            cout << "Yes" << endl;
            for(int i=e+1;i<=n;i++){
                if(visited[i] == 0)
                    cout << i << endl;
            }
            for(int i=0;i<m;i++)
                cout << arr[i] << endl;
        }
        else if(count >= m) {
            cout << "No" <<endl;
        }
        else{
            bool tr =true;
            for(int i=1;i<=count;i++){
                if(arr[i] < e){
                    tr = false;
                    break;
                }
            }
            int count2 =0;
            for(int i=1;i<m;i++){
                if(arr[i] > e)
                    count2++;
            }
            if(!tr || count2 >= count) {
                cout << "No" << endl;
            }
            else{
                cout << "Yes" <<endl;
                for(int i=e+1;i<=n;i++){
                    if(visited[i] == 0)
                        cout << i << endl;
                }
                for(int i=0;i<m;i++)
                    cout << arr[i] << endl;
                for(int i=1;i<e;i++){
                    if(visited[i] == 0)
                        cout << i << endl;
                }
            }

        }

    }
    return 0;
}