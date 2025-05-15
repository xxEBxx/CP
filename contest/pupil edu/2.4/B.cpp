#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
//keep track of when he dies to compare with his position
//time he dies < position else i lost;
struct monster{
    ll pow;
    ll pos;
};

bool comp(monster a,monster b){
    return a.pos < b.pos ;
}

int main(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        vector<monster> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i].pow;
        }
        for(int i=0;i<n;i++){
            cin>>v[i].pos;
            v[i].pos=abs(v[i].pos);
        }
        //priority_queue<monster,vector<monster,comp>> heap;
        sort(v.begin(),v.end(),comp);
        //7ta nbghi ndrbo 3ad n9sslo position
        ll sec=0,res=1;
        while(!v.empty()){
            if(v[0].pow > 0){
                ll time_kill = v[0].pow / k;
                v[0].pow -= time_kill * k;

                if (v[0].pow > 0) {
                    time_kill++;
                    if (sec + time_kill > v[0].pos) {
                        res = 0;
                        break;
                    }

                    ll chyata=k-v[0].pow , i=1;
                    while (i < v.size()) {
                        if(chyata >= v[i].pow){
                            chyata-=v[i].pow;
                            v.erase(v.begin()+i);
                            i--;
                        }
                        else{
                            v[i].pow-=chyata;
                            break;
                        }
                        i++;
                        //cout<<"pos-th tdrb bchyata w wla fih"<<v[1].pos<<" "<<v[1].pow<<endl;
                    }
                }
                //cout<<"time to kill pos-th "<<v[0].pos<<" "<<sec+time_kill<<endl;

                if (sec + time_kill > v[0].pos) {
                    res = 0;
                    break;
                }
                sec += time_kill;
            }
            v.erase(v.begin());
        }
        if(res==1)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}