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
string max_elem;
int main(){fast();
    string x,b;
    int kkk = 0;
    cin>>x>>b;
    max_elem=b;
    int res=0;
    int nw=1;
    for(char elem:x){
        if(elem!='0')
            nw=0;
    }
    if(nw){
          cout<<0;
          return 0;
    }
     if(b=="0"){
         cout<<"NO WAY"<<endl;
     }
     
     if (b.size()==x.size() && b >= x){
         cout<<0;
     }

    for(int i=x.size()-1;i>=0;){
        string word="";
        int j=i;
        for(j=max(0,i-(int)max_elem.size()+1);j <= i;j++){
            word = word + x[j];
        }


        j = max(0,i-(int)max_elem.size()+1);
        if(word.size() < max_elem.size()){
            break;
        }
        if(word > max_elem){
            j++;
        }
        while(x[j] == '0')j++;

        if(j>i){
            kkk = 1;
            break;
        }
        max_elem=x.substr(j,i-j+1);
        i = j - 1;
        res++;
        cout<<"new word "<<max_elem<<endl;
    }
    if(kkk== 0)cout<<res<<endl;
    else cout << "NO WAY"<<endl;

    return 0;
}