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

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const int maxn=(int)2*1e5+7;
const int mod=(int)1e9+7;

int main(){fast();
    int n;cin >> n;
    vector<vector<char>> arr(3,vector<char> (3,'*'));
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            cin >> arr[i][j];
    }
    if(n==0){
        cout << '*';
        return 0;
    }
    int l = 3,prev;
    for(int i=1;i<n;i++){
        prev = l;
        l *= 3;
        vector<vector<char>> arr2(l,vector<char> (l,'*'));
        for(int j=0;j<l;j++){
            for(int k=0;k<l;k++){
                if(arr[j/prev][k/prev] == '.')
                    arr2[j][k] = '.';
                else
                    arr2[j][k] = arr[j%prev][k%prev];
            }
        }
        arr = arr2;
    }
    for(int i=0;i<l;i++){
        for(int j=0;j<l;j++)
            cout << arr[i][j];
        cout << endl;
    }
    return 0;
}
