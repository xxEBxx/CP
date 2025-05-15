#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first

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
        int n;cin>>n;
        vi arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        if(n<4) {
            cout << n << endl;
            return 0;
        }
        map<int ,int > count;
        count[arr[1]]++;
        count[arr[0]]++;
        count[arr[2]]++;
        int i=0,j=3,current=3,total=3,s=0;
        for(auto elem:count)
            s++;

        while(j<n){
            if(s==3){
                if(count[arr[j]] != 0){
                    count[arr[j]]++;
                    j++;
                    current++;
                }
                else{
                    count[arr[i]]--;
                    if(count[arr[i]]==0){
                        s--;
                    }
                    i++;
                    current--;
                }
            }
            else{
                if(count[arr[j]]==0)
                    s++;
                count[arr[j]]++;
                j++;
                current++;
            }
            total=max(total,current);
        }
        cout<<total;

    return 0;
}