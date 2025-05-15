#include<bits/stdc++.h>// for vector

using namespace std;

void customInsert(vector<string>& v, string s) {
    int a = 0;
    while (a < v.size() && v[a] < s) {
        a++;
    }
    v.insert(v.begin() + a, s);
}

string small_two(string a,string b){
    int i=0,n=a.size(),m=b.size(),less=min(n,m);
    string res="";
    while(b[i]==a[i] && i<n && i<m){
        res+=a[i];
        i++;
    }
    //cout<<"Diff"<<b[i]-a[i]<<i<<endl;
    //ici on a la premiere difference
    if(b[i]-a[i]>1){
        res += (char) ((int) a[i] + 1);
        return res;
    }
    if(i<n-1 && i<m-1) {
        res += (char) ((int) a[i] + 1);
        return res;
    }
    if(i==m-1 && i<n-1){
        res += (char) ((int) a[i]);
        if(i==n-2){
            res += (char) ((int) a[i+1]);
        }
        else{
            res += (char) ((int) a[i+1]+1);
        }
        return res;
    }
    if(i==n-1 && i<m-1){

    }
    return a;
}

int main() {
    int n;
    string temp;
    cout<<small_two("ACX","B");
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        cin.ignore();
        vector<string> v;
        for (int i = 0; i < n; i++) {
            getline(cin, temp);
            customInsert(v, temp);
        }
        cout<<small_two(v[n/2-1],v[n/2])<<endl;
    }
    return 0;
}
