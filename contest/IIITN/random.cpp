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
    int n=6;
    vi arr1(n),arr2(n),arr3(n);
    for(int i=0;i<n;i++)
        cin>>arr1[i];
    for(int i=0;i<n;i++)
        cin>>arr2[i];
    for(int i=0;i<n;i++)
        cin>>arr3[i];

    int win12=0,win23=0,win31=0,win21=0,win32=0,win13=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr1[i] >= arr2[j])
                win12++;
            if(arr1[i] <= arr2[j])
                win21++;

            if(arr2[i] >= arr3[j])
                win23++;
            if(arr2[i] <= arr3[j])
                win32++;

            if(arr3[i] >= arr1[j])
                win31++;
            if(arr3[i] <= arr1[j])
                win13++;
        }
    }


    if(arr1==arr2 && win23>=18) {
        bool same=true;
        for(int i=0;i<n-1;i++){
            if(arr2[i]!=arr2[i+1]){
                same=false;
            }
        }
        if(same){
            cout << "No dice" << endl;
            return 0;
        }
    }
    else if(arr1==arr3 && win12>=18){
        bool same=true;
        for(int i=0;i<n-1;i++){
            if(arr1[i]!=arr1[i+1]){
                same=false;
            }
        }
        if(same){
            cout << "No dice" << endl;
            return 0;
        }
    }
    else if(arr2==arr3 && win21>=18){
        bool same=true;
        for(int i=0;i<n-1;i++){
            if(arr2[i]!=arr2[i+1]){
                same=false;
            }
        }
        if(same){
            cout << "No dice" << endl;
            return 0;
        }
    }

    //cout<<win12<<" "<<win23<<" "<<win31<<endl;
    if(win12 >=18 && win13>=18)
        cout<<1<<endl;
    else if(win23 >= 18 && win21>=18)
        cout<<2<<endl;
    else if(win31 >= 18 && win32 >= 18)
        cout<<3<<endl;
    else
        cout<<"No dice"<<endl;

    return 0;
}