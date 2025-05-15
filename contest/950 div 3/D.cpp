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

bool work(vector<int> arr,int i){
    int n=arr.size();
    vector<int> arr1;
    for(int j=0;j<n;j++){
        if(i==j) continue;
        arr1.push_back(arr[j]);
    }
    vector<int> pgcd(n-2);
    for(int j=0;j<n-2;j++){
        pgcd[j]=gcd(arr1[j],arr1[j+1]);
        //cout<<pgcd[j]<<" ";
    }
    //cout<<endl;
    for(int j=0;j<n-3;j++){
        if(pgcd[j] > pgcd[j+1]){
            //cout<<"false;";
            return false;
        }
    }
    //cout<<"true;";
    return true;
}

string solve(vector<int> arr){
    int n=arr.size();
    vector<int> pgcd(n-1);
    for(int i=0;i<n-1;i++){
        pgcd[i]=gcd(arr[i],arr[i+1]);
    }
    for(int i=0;i<n-2;i++){
        if(pgcd[i] > pgcd[i+1]){
                if(work(arr,i) || work(arr,i+1) || work(arr,i+2)){
                    return "Yes";
                }
                else{
                    return "No";
                }
        }
    }
    return "Yes";
}

int main(){fast();
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<solve(arr)<<endl;
    }
    return 0;
}