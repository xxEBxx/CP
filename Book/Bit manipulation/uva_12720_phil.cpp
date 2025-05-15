#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,kk=0;
    cin>>n;
    cin.ignore();
    //cout<<n;
    while(n--){
        kk++;
        string s;
        getline(cin,s);
        //cout<<s;
        string res="";
        cout<<"Case #"<<kk<<": ";
        if (s.size() % 2 == 1) {
            res+=s[s.size()/2];
            s.erase(s.begin() + s.size() / 2); // Remove the middle character
        }
        while (s.size()>0){
            int i=s.size()/2-1;
            if(s[i]!=s[i+1]){
                res+='1';
                res+='0';
            }
            else{
                res+=s[i];res+=s[i+1];
            }
            s.erase(s.begin() + i);
            s.erase(s.begin() + i);
        }
        reverse(res.begin(),res.end());
        //cout<<"reversed:"<<res;
        int ans=0;
        for(int i=0;i<res.size();i++){
            if(res[i]=='0'){
                continue;
            }
            else if (res[i]=='1'){
                ans += (1 << i);
                ans = ans % 1000000007;
                //cout << "curr_sum=" << ans;
            }
        }
        cout<<ans<<endl;
    }
}