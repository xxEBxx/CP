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

struct node{
    int index,needed,done;
};
bool comp(node a,node b){
    if(a.done!=b.done)return a.done >= b.done;
    return a.index<b.index;
}
int main(){
    int n,m;cin>>n>>m;
    vector<node> row(n),col(m);
    for(int i=0;i<n;i++){
        row[i].index=i;
        row[i].needed=m;
        cin>>row[i].done;
    }
    for(int i=0;i<m;i++){
        col[i].index=i;
        col[i].needed=n;
        cin>>col[i].done;
    }

    sort(all(row),comp);
    sort(all(col),comp);
    int i=0,j=0;
    string result;
    result="";
    for(int ii=0;ii<m+n;ii++){
        if(j<m && col[j].done == col[j].needed){
            result += "c" + to_string(col[j].index + 1) + " ";
            j++;
            for(int index=0;index<n;index++){
                row[index].needed--;
            }
        }
        else if(i<n && row[i].done == row[i].needed){
            result += "r" + to_string(row[i].index + 1) + " ";
            i++;
            for (int index = 0; index < m; index++) {
                col[index].needed--;
            }
        }
        else {
            cout<<-1;
            return 0;
        }
    }
    cout<<result;

    return 0;
}