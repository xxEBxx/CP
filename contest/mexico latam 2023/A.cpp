//
// Created by benje on 10/24/2024.
//
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
    ll n;
    cin >> n;
    ll a = sqrt(n);
    ll start = a*(a+1)/2;
    ll end = n - a*(a-1)/2;
    ll count = 2*a -1;
    ll k = end - start;
    while(k > 0){
        if(k%a == 0) {
            count += k / a;
            break;
        }
        if (k/a > 1){
            k-= a;
            count++;
        }
        else{
            if(k%a == a-1){
                k-= a;
                a--;
                count++;
            }
            else
                a--;
        }
    }
    cout << count;

    return 0;
}