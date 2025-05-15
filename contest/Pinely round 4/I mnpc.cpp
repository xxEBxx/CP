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
    int n,p;cin>>n>>p;
    vi degree(p+1,0),right(p+1,-1),left(p+1,-1),passed(1+p,0);

    //for topoligical sort
    for(int i=1;i<=p;i++){
        int r,l;cin>>l>>r;
        if(l != p+1) {
            degree[l]++;
            left[i]=l;
        }
        if(r != p+1) {
            degree[r]++;
            right[i]=r;
        }
    }
    for(int i=2;i<=p;i++){
        if(degree[i]==0){
            if(right[i]!=-1){
                degree[right[i]]--;
            }
            if(left[i]!=-1){
                degree[left[i]]--;
            }
        }
    }
    string s;cin>>s;
    queue<int> q;
    q.push(1);
    passed[1]=n;
    while(!q.empty()){

        int parent=q.front();
        //cout<<right[parent];
        //cout<<"here is parent"<<parent<<right[parent]<<left[parent]<<endl;
        if(right[parent] != -1){
            if(s[parent-1] == 'L')passed[right[parent]] += passed[parent]/2;
            else passed[right[parent]] += (passed[parent]+1)/2;
            degree[right[parent]]--;
            if(degree[right[parent]]==0)q.push(right[parent]);
        }

        if(left[parent] != -1){
            if(s[parent-1]=='R')passed[left[parent]] += passed[parent]/2;
            else passed[left[parent]] += (passed[parent]+1)/2;
            degree[left[parent]]--;
            if(degree[left[parent]]==0)q.push(left[parent]);
        }
        //cout<<q.front()<<endl;
        q.pop();
        //if(!q.empty())cout<<q.front()<<endl<<endl;

    }

    for(int i=0;i<p;i++){
        //cout<<passed[i+1]<<" ";
        if(passed[i+1] % 2 == 1){
            //cout<<"hi"<<i;
            if(s[i]=='L')s[i]='R';
            else s[i]='L';
        }
    }

    cout<<s<<endl;
    return 0;
}