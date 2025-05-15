//link :https://vjudge.net/problem/UVA-11804

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
struct elem{
    int d,a;
    string name;
};
bool sort_name(elem a, elem b){
    return a.name>b.name;
}

int main(){fast();
    int t;cin>>t;int kk=0;
    while(t--){
        kk++;
        int n;cin>>n;
        vector<elem> arr(10);
        for(int i=0;i<n;i++){
            cin>>arr[i].name>>arr[i].a>>arr[i].d;
        }
        //sort(all(arr),sort_name);
        int indexes[5],att=0,def=0;
        for(int i=0;i<6;i++){
            for(int j=i+1;j<7;j++){
                for(int k=j+1;k<8;k++){
                    for(int l=k+1;l<9;l++){
                        for(int m=l+1;m<10;m++){
                            int attack=arr[i].a+arr[j].a+arr[k].a+arr[l].a+arr[m].a,defense=0;
                            for(int ii=0;ii<10;ii++){
                                if(ii!=i && ii!=j && ii!=k && ii!=l && ii!=m){
                                    defense+=arr[i].d;
                                }
                            }
                            if(attack > att || (attack==att && defense > def)){
                                indexes[0]=i;
                                indexes[1]=j;
                                indexes[2]=k;
                                indexes[3]=l;
                                indexes[4]=m;
                                att=attack;
                                def=defense;
                            }
                        }
                    }
                }
            }
        }
        for(int kkk:indexes)cout<<kkk<<" ";
        cout<<endl;
        vector<string> ans_attack,ans_defense;
        int start=0;
        for(int i=0;i<10;i++){
            if(indexes[start]==i){
                ans_attack.push_back(arr[i].name);
                start++;
            }
            else ans_defense.push_back(arr[i].name);
        }


        cout<<"Case "<<kk<<":\n(";
        for(int i=0;i<4;i++)cout<<ans_attack[i]<<", ";
        cout<<ans_attack[4]<<")\n(";
        for(int i=0;i<4;i++)cout<<ans_defense[i]<<", ";
        cout<<ans_defense[4]<<")\n";

    }
    return 0;
}