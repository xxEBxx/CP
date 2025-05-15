#include<bits/stdc++.h>

using namespace std;
#define maxn 7
vector<bool> visited(maxn,false);
char start,last;
unordered_map<char, vector<char>> m;

string path(string prev,char curr){
    visited[curr - 'A'] = true;
    if(curr==last)return prev+curr;
    for(char c:m[curr]){
        if(!visited[c-'A']){
            string res = path(prev + curr, c);
            if (!res.empty()) // If we found a path, return it
                return res;
        }
    }
    return "";
}

int main(){
    int n;cin>>n;
    char a,b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        m[a].push_back(b);
        m[b].push_back(a);
    }
    cin>>start>>last;
    //string word="";word+=start;
    cout<<path("",start);
}
/*
 4
A B
A C
B C
C E
A E

 */