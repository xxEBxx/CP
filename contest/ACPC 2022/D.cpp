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
        ll count = 1 ,count1 = 0;
        int n;
        cin >> n;
        vector<pair<string,ll>> arr(n);
        for(int i=0;i<n;i++)
            cin >> arr[i].f >> arr[i].s;
        for(int i=1;i<n;i++){
            if(arr[i].f != arr[i-1].f)
                count++;
        }
        vector<string> st(count);
        vector<vector<ll>> liste(count);
        liste[0].push_back(0);
        int j =0;
        st[j] = arr[0].f;
        for(int i=1;i<n;i++){
            if(arr[i].f != arr[i-1].f){
                j++;
                st[j] = arr[i].f;
            }
            liste[j].push_back(i);
        }
        count1 =n;
        j = 0;
        while(count1 > 0){
            for(int i=0;i<count;i++){
                if(j < liste[i].size()){
                    cout << st[i] << " " << arr[liste[i][j]].s << endl;
                    count1--;
                }
            }
            j++;
        }
    }
    return 0;
}