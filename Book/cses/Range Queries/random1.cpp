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

int n;

string solve(int size,string a,int to_left){
    //we are sure a exist
    if(size==n){
        return a;
    }
//we try to make one of the four accepted

    if(to_left==0){
        int ans;
        cout<<"? "<<a<<"1"<<endl;
        cin>>ans;
        if(ans==1){
            return solve(size+1,a+"1",0);
        }
        cout<<"? "<<a<<"0"<<endl;
        cin>>ans;
        if(ans==1){
            return solve(size+1,a+"0",0);
        }
        else{
            return solve(size,a,1);
        }
    }
    int ans;
    cout<<"? 1"<<a<<endl;
    cin>>ans;
    if(ans==1)
        return solve(size+1,"1"+a,1);

    return solve(size+1,"0"+a,1);

}

int main(){
    int t;cin>>t;
    while(t--){
        cin>>n;
        cout<<"?"<<" 0"<<endl;
        int ans;
        cin>>ans;
        if(ans==1) {
            string res = solve(1, "0",0);
            cout<<"! "<<res<<endl;
        }

        else {
            cout<<"! ";
            for(int i=0;i<n;i++)
                cout<<1;
            cout<<endl;
        }

    }
    return 0;
}