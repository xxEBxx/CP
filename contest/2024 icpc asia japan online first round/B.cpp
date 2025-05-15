#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef pair<ll,ll> pl;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;

const ll maxn=(ll)1e6+7;
const ll mod=(ll)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int main(){fast();
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<ll> my_white,my_black,opp_white,opp_black;
        for(ll i=0;i<n;i++){
            ll power,type;
            cin>>power>>type;
            if(type==1){
                my_black.push_back(power);
            }
            else{
                my_white.push_back(power);
            }
        }

        for(ll i=0;i<n;i++){
            ll power,type;
            cin>>power>>type;
            if(type==1){
                opp_black.push_back(power);
            }
            else{
                opp_white.push_back(power);
            }
        }

        sort(all(my_white));
        sort(all(my_black));
        sort(all(opp_black));
        sort(all(opp_white));


        ll k = opp_black.size()-my_black.size();
        string answer="YES";
        if(k>0){
            //enemy has k more black => i have k more white
            //i kill k black with k white
            ll index=0;
            for(ll i=0;i<k && index<n;){
                if(my_white[index] >= opp_black[i]){
                    my_white[index]=-1;
                    opp_black[i]=-1;
                    i++;
                }
                index++;
            }
            if(index==n){
                answer="NO";
            }
            //now white vs white and black vs black
            ll i=k;
            while(i<opp_black.size()){
                //black vs black
                if(opp_black[i] > 2 * my_black[i-k]){
                    answer="NO";
                }
                i++;
            }
            //white vs white ,enemy doesnt have much whites
            i=0,index=0;
            while(i<opp_white.size()){
                if(my_white[index]==-1){
                    index++;
                    continue;
                }
                else if(my_white[index]*2 < opp_white[i]){
                    answer="NO";
                    break;
                }
                index++;
                i++;
            }
            cout<<answer<<endl;
        }
        else if(k<0){
            k=-k;
            //enemy has k more black => i have k more white
            //i kill k black with k white
            ll index=0;
            for(ll i=0;i<k && index<n;){
                if(my_black[index] >= opp_white[i]){
                    my_black[index]=-1;
                    opp_white[i]=-1;
                    i++;
                }
                index++;
            }
            if(index==n){
                answer="NO";
            }
            //now white vs white and black vs black
            ll i=k;
            while(i<opp_white.size()){
                //black vs black
                if(opp_white[i] > 2 * my_white[i-k]){
                    answer="NO";
                }
                i++;
            }
            //white vs white ,enemy doesnt have much whites
            i=0,index=0;
            while(i<opp_black.size()){
                if(my_black[index]==-1){
                    index++;
                    continue;
                }
                else if(my_black[index]*2 < opp_black[i]){
                    answer="NO";
                    break;
                }
                index++;
                i++;
            }
            cout<<answer<<endl;
        }
        else{
            for(ll i=0;i<opp_black.size();i++){
                if(opp_black[i] > 2 * my_black[i] ){
                    answer="NO";
                }
            }

            for(ll i=0;i<opp_white.size();i++){
                if(opp_white[i] > 2 * my_white[i] ){
                    answer="NO";
                }
            }
            cout<<answer<<endl;
        }


    }
    return 0;
}