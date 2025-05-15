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
    vector<int> arr;
    for(int i=0;i<5;i++){
        int val;cin>>val;
        arr.push_back(val);
    }
    sort(all(arr));
    int sum=arr[0]+arr[1]+arr[2]+arr[3];
    int points_index=-1;
    for(int i=0;i<4;i++){
        if(arr[4] == sum-arr[i]){
            points_index=i;
            break;
        }
    }

    vi res(5);
    vi num;
    if(points_index != -1) {
        res[0] = arr[4];
        res[4] = arr[points_index];
        for (int i = 0; i < 4; i++) {
            if (i == points_index)continue;
            num.push_back(arr[i]);
        }
    }else {
        res[0] = arr[3];
        res[4] = arr[4];
        for (int i = 0; i < 3; i++) {
            num.push_back(arr[i]);
        }
    }
    if (num[0] * 3 + num[1] == res[4]) {
        res[1] = num[0];
        res[2] = num[1];
        res[3] = num[2];
    }
    if (num[0] + num[1] * 3 == res[4]) {
        res[1] = num[1];
        res[2] = num[0];
        res[3] = num[2];
    }
    if (num[2] + num[1] * 3 == res[4]) {
        res[1] = num[1];
        res[2] = num[2];
        res[3] = num[0];
    }
    if (num[2] * 3 + num[1] == res[4]) {
        res[1] = num[2];
        res[2] = num[1];
        res[3] = num[0];
    }
    if (num[2] * 3 + num[0] == res[4]) {
        res[1] = num[2];
        res[2] = num[0];
        res[3] = num[1];
    }
    if (num[2] + num[0] * 3 == res[4]) {
        res[1] = num[0];
        res[2] = num[2];
        res[3] = num[1];
    }

    for(auto elem:res)
        cout<<elem<<" ";

    return 0;
}