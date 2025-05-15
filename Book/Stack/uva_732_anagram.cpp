#include<bits/stdc++.h>

using namespace std;

string solve_once(string o,string c){
    stack<char> s;
    int n=o.size(),i=0,j=1;
    //i is for search in copy
    //j is for parcours in original
    s.push(o[0]);
    string output="i";
    while(i<n && j<n+2){
        //cout<<"o then c "<<o[j]<<c[i]<<endl;
        if(!s.empty()){
            //cout<<"top: "<<s.top()<<endl;
            if(s.top()==c[i]){
                s.pop();
                i++;
                output+=" o";
                continue;
            }
            else{
                //cout<<"pushed"<<o[j]<<"  ";
                s.push(o[j]);
                j++;
                output+=" i";
                continue;
            }
        }
        else{
            s.push(o[j]);
            j++;
            output+=" i";
            continue;
        }
    }
    if(j>n)return "";
    return output;
}
void solve(string o, string c){
    int letter=97,n=o.size();
    vector<pair<int,int>> perm;
    set<int> red;
    for(int i=0;i<n;i++){
        if(arr[i])
    }
}
int main(){
    string o,c;
    while(getline(cin,o)){
        getline(cin,c);
        cout<<solve_once(o,c);
        //cout<<"hey";
    }
}
/*
bAhBmC
bBhCmA

 2
 3
4
*/
