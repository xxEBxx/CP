#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,int> pl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<int> vl;
typedef vector<vector<int>> vvl;

const int maxn=(int)1e6+7;
const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

bool comp(pair<int,pair<int,int>> a , pair<int,pair<int,int>> b){
    return a.f<b.f;
}

int main(){fast();
    string s;cin>>s;
    s = '0'+s;
    int q;cin>>q;
    vector<pair<int,pair<int,int>>> m;
    set<int> visited;
    for(int i=1;i<s.size();i++){
        int num=s[i]-'0';
        pair<int,pair<int,int>> obj;
        if( *visited.lower_bound(num) != num){
            obj.s.f=i;
            obj.s.s=i;
            obj.f=num;
            visited.insert(num);
            m.push_back(obj);
        }
        //if(num==0)continue;
        for(int j=i+1;j < (int)s.size() && num <= (int)1e9 ;j++){
            num *= 2;
            num += s[j] - '0';
            //cout<<"here is num "<<num<<endl;
            if( *visited.lower_bound(num) != num ){
                obj.s.f=i;
                obj.s.s=j;

                obj.f=num;
                visited.insert(num);
                m.push_back(obj);
            }
        }
    }

    //for(auto elem : m)cout<<elem.f<<" "<<elem.s.f<<" "<<elem.s.s<<endl;
    sort(all(m),comp);

    for(int i=0;i<q;i++){
        int a,b;cin>>a>>b;
        auto it = lower_bound(all(m), make_pair(a, make_pair((int)1e9,(int)1e9)));

        if(it != m.end() && it->s.s <= b){
            cout<<it->s.f<<" "<<it->s.s<<endl;
        }
        else
            cout<<"-1 -1"<<endl;

    }

    return 0;
}