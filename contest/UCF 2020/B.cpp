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
struct node {
    int e,v1,v2;
};
int main(){fast();
    int n;
    cin >> n;
    vector<node> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i].e >> arr[i].v1 >> arr[i].v2;
    int count1 = 0,count2=0;
    int tot1 = 0,tot2 = 0;
    for(int i=0;i<n;i++){
        if(arr[i].v2 > arr[i].v1)
            count2 += arr[i].e;
        else
            count1+= arr[i].e;
        tot1+= arr[i].v1;
        tot2+= arr[i].v2;
    }
    if(tot2 > tot1 && count2> count1)
        cout << 2 ;
    else if(tot1 > tot2 && count1 > count2)
        cout << 1 ;
    else
        cout << 0;
    return 0;
}