#include<bits/stdc++.h>

using namespace std;
unordered_map<int,vector<int>> m;
vector<bool> passed(30,false);
unordered_map<int,int> d;

void solve(int base){
    queue<int> q;
    q.push(base);
    passed[base]=true;
    cout << base << ": 0"<< endl;
    int depth=1;
    while(!q.empty()){
        int top=q.front();
        for(int k : m[top]){
            if(!passed[k]){
                d[depth]++;
                passed[k] = true;
                cout << k << ": " << depth << endl;
                q.push(k);
                if(d[depth]==0){
                    depth++;
                }
                else{
                    d[depth]--;
                }
            }
        }
        q.pop();
    }
}

int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        m[a].push_back(b);
        m[b].push_back(a);
    }
    solve(2);
}
/*
4
1 2
3 4
3 2
4 5
 */
