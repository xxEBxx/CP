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
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    int m1,m2;
    int out = 0;
    for(int i=0;i<n;i++){
        if(arr[i] == 1)
            break;
        if(arr[i] == -1){
            int j = n-1;
            while(arr[j] == 0)
                j--;
            out = j-i +1 ;
            cout << out;
            return 0;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(arr[i] == -1)
            break;
        if(arr[i] == 1){
            int j = 0;
            while(arr[j] == 0)
                j++;
            out = i-j +1 ;
            cout << out;
            return 0;
        }
    }
    int i=0;
    int a,b;
    bool tr1 = true;
    bool tr2 = true;
    while(i < n){
        if(tr1 && arr[i] == 1) {
            a = i;
            tr1 = false;
        }
        if(arr[i] == -1){
            b = i;
            break;
        }
        i++;
    }
    m1 = b - a;
    i = n-1;
    while(i >= 0){
        if(tr2 && arr[i] == -1) {
            a = i;
            tr2 = false;
        }
        if(arr[i] == 1){
            b = i;
            break;
        }
        i--;
    }
        m2 = a -b;
        int m = min(m1,m2);
        int dis = m/2;
        int low,up;
        i = 0;
        while(i < n){
            if(arr[i] != 0){
                low = i;
                break;
            }
            i++;
        }
        low += dis;
        i = n-1;
        while(i >= 0){
            if(arr[i] != 0){
                up = i;
                break;
            }
            i--;
        }
        up -= dis;
        out = up - low + 1;
        if(m%2 == 1)
            out--;
        cout << out;
    return 0;
}