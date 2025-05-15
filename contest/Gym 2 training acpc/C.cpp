#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>


using namespace std;

typedef long long ll;




void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

}

int main(){

    fast();
    int t;cin>>t;
    while(t--){
        ll n,k;

        cin >> n >> k;
        k--;
        ll res = 0;
        if(k == 0){
            cout << n << "\n";
            continue;
        }
        else{
            for(ll i=1;i<= (ll)sqrt(k) ;i++){
                //cout<<i<<" ";
                if(k%i==0 && i<=n){
                    //cout<<"f";
                    res++;
                    if(i*i != k && k/i <=n && i<k/i) {
                        //cout<<"s";
                        res++;
                    }
                }
                //cout<<endl;
            }
        }
        cout<<res<<endl;
    }
}