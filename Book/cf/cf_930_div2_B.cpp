#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();
        vector<string> v(2);
        getline(cin, v[0]);
        getline(cin, v[1]);
        string res = "";res+=v[0][0];
        int i = 0, rep = n;
        //etage=0
        while (i < n-1) {
            //cout<<"enterred the loop i:" <<i<<endl;
            if(v[0][i+1]=='0'){
                res+='0';
                if(v[1][i]=='1'){
                    rep--;
                }
                i++;
            }
            else{
                if(v[1][i]=='1'){
                    i++;
                    res+='1';
                }
                else{
                    rep-=n-i;
                    break;
                }
            }
            //cout<<"res"<<res<<endl;
        }
        //cout<<"i after loop"<<i<<endl;
        while(i<n){
            res+=v[1][i];
            i++;
        }
        cout<<res<<endl<<max(1,rep)<<endl;
    }
}