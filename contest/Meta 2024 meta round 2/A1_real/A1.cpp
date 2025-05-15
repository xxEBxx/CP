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
vector<ll> nums = {1,2,3,4,5,6,7,8,9,121,232,343,454,565,676,787,898,12321,23432,34543,45654,56765,67876,78987,1234321,2345432,3456543,4567654,5678765,6789876,123454321,234565432,345676543,456787654,567898765,12345654321,23456765432,34567876543,45678987654,1234567654321,2345678765432,3456789876543,123456787654321,234567898765432,12345678987654321};

int main(){fast();
    int t,tt=0;
    cin >> t;
    while(t--) {tt++;
        cout << "Case #"<<tt<<": ";
        ll A,B,M;
        cin >> A >> B >> M;
        ll count =0;
        for(int j=0;j<nums.size();j++) {
            if(nums[j]>= A && nums[j]<= B) {
                if(nums[j]%M == 0)
                    count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}