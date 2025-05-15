#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<double,double> ii;
typedef pair<ll,ll> pl;
typedef vector<double> vi;
typedef vector<vector<double>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const int maxn=(double)2*1e5+7;
const double mod=(double)1e9+7;
double arr[maxn],w[maxn];
int n,l;

bool work(double x) {
    double t =0.0;
    double stop =0.0;

    for(int i=0;i<n;i++){
        //we go from our place to next stop;
        t += (arr[i]-stop)/x;

        //wait for other to come if we were too early
        t = max(t,arr[i]);

        t += w[i];
        stop = arr[i];

        if(t > l)return false;
    }
    t += (l-stop)/x;
    t = max(t,(double)l);

    return t<=l;
}


int main(){fast();
    cin>>n>>l;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    arr[n]=l;
    w[n]=0;
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    double low=1,high = 3*1e8,mid =(low+high )/2;
    if(!work(high)){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }

    while(high - low > 0.00001){
        mid = (high+low)/2;
        if(work(mid))
            high = mid;
        else
            low = mid;
    }
    cout<<high<<endl;

    return 0;
}