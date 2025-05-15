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
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int m;cin>>m;
        for(int i=0;i<m;i++){
            string word;cin>>word;
            if(word.size()!=n){
                cout<<"No"<<endl;
                continue;
            }
            int max_num=1e9+2;
            vi check(28,max_num);//letter to number
            map<int,int> visited;
            map<int,char> m_num;//number to letter

            //sum of lentghs is smaller than 10 to5
            bool res=true;
            for(int j=0;j<n;j++){
                int index_letter=word[j]-'a';
                if(check[index_letter]==max_num && !visited[arr[j]]){
                    //both empty
                    check[index_letter]=arr[j];
                    visited[arr[j]]=1;
                    m_num[arr[j]]=word[j];
                }
                else if(check[index_letter]==max_num){
                    if(m_num[arr[j]] == word[j])
                        check[index_letter] = arr[j];
                    else {
                        res = false;
                        break;
                    }
                }
                else if(!visited[arr[j]]){
                    visited[arr[j]]=1;
                    if(check[index_letter]==arr[j]){
                        m_num[arr[j]]=word[j];
                    }
                    else{
                        res = false;
                        break;
                    }
                }
                else{
                    //both known
                    if(check[index_letter]==arr[j] && m_num[arr[j]] == word[j]){
                        continue;
                    }
                    else{
                        res = false;
                        break;
                    }
                }
            }
            if(res)cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}

