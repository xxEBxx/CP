#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;cin>>t;
    string letter="ACGT";
    while(t--){
        string res="",s;
        int n,m,error=0;
        cin>>n>>m;
        cin.ignore();
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=0;i<m;i++){
            map<char,int> m;
            for(int j=0;j<n;j++){
                m[arr[j][i]]++;
            }
            int max_value=0;char best_letter;
            for(char x:letter){
                if(m[x]>max_value){
                    max_value=m[x];
                    best_letter=x;
                }
            }
            error+=n - max_value;
            res+=best_letter;
        }
        cout<<res<<endl<<error<<endl;
    }
}