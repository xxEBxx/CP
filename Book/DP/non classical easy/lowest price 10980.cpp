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
    double unit;int offers;int tt=0;
    while(cin>>unit>>offers){tt++;
        vector<double> dp(102,1e9);
        dp[0]=0;
        dp[1]=unit;
        for(int i=0;i<offers;i++){
            int num;double price;
            cin>>num>>price;
            dp[num]=min(price,dp[num]);
        }
        //cout<<dp[97]<<endl;
        for(int i=2;i<102;i++){
            for(int j=0;j < i;j++){
                for(int k=i-j;k<102;k++){
                    dp[i]=min(dp[i],dp[j]+dp[k]);
                }
            }
            for(int k=1;k<i;k++)dp[k]=min(dp[k],dp[i]);
        }
        cin.ignore();
        string line;
        getline(cin,line);
        istringstream stream(line);
        //cout<<line<<endl;
        vi arr;
        int number;
        while(stream>>number)arr.push_back(number);
        cout<<"Case "<<tt<<":"<<endl;
        for(int i=0;i<arr.size();i++){
            cout<<"Buy "<<arr[i]<<" for $"<<fixed<<setprecision(2)<<showpoint<<dp[arr[i]]<<endl;
        }

    }
    return 0;
}

/*
 10.19 20
41 64.99
69 34.38
67 16.17
97 3.50
49 10.22
70 19.06
97 84.67
78 17.52
6 78.76
54 40.27
73 28.31
30 19.26
73 30.89
19 14.44
62 95.77
27 28.87
24 89.02
71 39.95
97 62.90
63 35.19
25 33 64 21 36 41 48 93 19 1 23 44 26 5 84 51 48
 */