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

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

const int maxn=(int)2*1e5+7;
const int mod=(int)1e9+7;

string miniscule[26]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
string majuscule[26]={"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};

int main(){fast();
    string s;
    getline(cin,s);
    int tresh=0 ;
    int first=0;
    while(!(('a' <= s[first] && s[first] <= 'z') || ('A' <= s[first] && s[first] <= 'Z'))){

        cout<<s[first];
        first++;
        tresh--;
    }
    if ('a' <= s[first] && s[first] <= 'z') {
        tresh += 'e' - s[first];
    } else {
        tresh += 'E' - s[first];
    }
    for(int i=first;i<s.size();i++){
        if('a'<=s[i] && s[i]<='z'){
            int index = (s[i]-'a'+ tresh) %26;
            if(index<0)index+=26;

            cout<<miniscule[index];
        }
        else if('A'<=s[i] && s[i]<='Z'){
            int index = (s[i]-'A'+ tresh) %26;
            if(index<0)index+=26;
            cout<<majuscule[index];
        }
        else{
            cout<<s[i];
        }
        tresh--;
    }
    cout<<endl;

    return 0;
}
//HRXOHA setbzxs woyip
//HRXOHA setbzxs uhhoapr
//Gqnte, ndsupoa-ysvedjd