#include<bits/stdc++.h>

using namespace std;
const int maxn=1e5+2;

int next_element(int n,int power,int prev,char dir){
    int res;
    if(dir=='0') {
        res= (power + prev) % n;
        if(res==0)return n;
        return res;
    }
    res=(prev-power)%n;
    if(res<=0)return res+n;
    return res;
}

void print_arr(vector<int> a){
    for(int k:a){
        cout<<k<<" ";
    }
    cout<<endl;
}
int main(){
    int t;cin>>t;
    while(t--){
        int n,m,x;
        cin>>n>>m>>x;
        set<int> poss;
        poss.insert(x);
        for(int i=0;i<m;i++){
            set<int> new_pos;
            int a;char b;
            cin>>a>>b;
            //cout<<b;
            if(b=='?'){
                for(int i:poss){
                    new_pos.insert(next_element(n,a,i,'1'));
                    new_pos.insert(next_element(n,a,i,'0'));
                }
            }
            else{
                for(int i:poss){
                    new_pos.insert(next_element(n,a,i,b));
                }
            }
            //print_arr(new_poss);
            poss=new_pos;
            for(int a:poss){
                //cout<<a<<" ";
            }
            //cout<<endl;
        }
        cout<<poss.size()<<endl;
        for(int a:poss){
            cout<<a<<" ";
        }
        cout<<endl;
    }
}