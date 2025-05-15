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
    int a;cin>>a;
    vector<char> digits;

    int cop=a;
    while(cop > 0){
        digits.push_back((char)('0'+ cop%10));
        cop/=10;
    }
    reverse(all(digits));
    bool isFirst=true;
    if(digits[0]=='1'){
        isFirst=false;
    }
    char to_change='0'+12;
    if(isFirst){
        to_change=digits[0];
    }
    else{
        for (int i = 1; i < digits.size(); i++) {
            if (digits[i] == '0' || digits[i]=='1')continue;
            to_change = digits[i];
            break;
        }
    }
    vector<char> min_;
    for(int i=0;i<digits.size();i++){
        if(digits[i]==to_change){
            if(isFirst)min_.push_back('1');
            else min_.push_back('0');
        }
        else{
            min_.push_back(digits[i]);
        }
    }

    isFirst=true;
    if(digits[0]=='9'){
        isFirst=false;
    }
    to_change='0'+10;

    if(isFirst){
        to_change=digits[0];
    }
    else{
        for (int i = 1; i < digits.size(); i++) {
            if (digits[i] == '9')continue;
            to_change = digits[i];
            break;
        }
    }
    vector<char> max_;
    for(int i=0;i<digits.size();i++){
        if(digits[i]==to_change){
            max_.push_back('9');
        }
        else{
            max_.push_back(digits[i]);
        }
    }
    int max_elem=0,min_elem=0;
    for(int i=0;i<digits.size();i++){
        max_elem*=10;
        min_elem*=10;
        max_elem += max_[i]-'0';
        min_elem += min_[i]-'0';
    }
    cout<<max_elem-min_elem<<endl;
    return 0;
}