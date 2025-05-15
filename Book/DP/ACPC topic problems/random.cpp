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
vi arr;
int n;
bool solve(int x,int count){
    int index_start=lower_bound(all(arr),x)-arr.begin();
    int have=n-index_start, needed=x-have;
    if(index_start < needed)return false;
    for(int i=index_start-1 ; i>=index_start-needed;i--){
        int num=arr[i];
        while(num < x){
            num*=2;
            count--;
        }
        if(count<0)return false;
    }
    return true;
}

int main(){fast();
    int t;cin>>t;
    while(t--){
        cin>>n;
        arr.resize(n);
        int count=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            while(arr[i]%2==0){
                arr[i]/=2;
                count++;
            }
        }
        sort(all(arr));
        //for(int elem:arr )cout<<elem<<" ";
        int a=1,b=200000,middle=(a+b)/2;;
        while(b-a>1){
            if(solve(middle,count))
                a=middle;
            else
                b=middle-1;
            middle=(a+b)/2;
            //cout<<middle<<endl;
        }
        if(solve(b,count))cout<<b<<endl;
        else cout<<middle<<endl;


    }
    return 0;
}