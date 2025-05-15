#include<bits/stdc++.h>

using namespace std;
unordered_map<int,vector<int>> m;
vector<int> passed(30,false);
int c(char a){
    return a-'A';
}

string find_component(string prev,char curr){
    passed[c(curr)]=true;
    string res=prev+curr;
    //cout<<"entered to curr= "<<curr<<endl;
    for(int elem :m[c(curr)]){
        //cout<<"     here is elem " <<(char)(elem+'A')<<endl;
        if(!passed[elem]){
            //res += (char)('A'+elem);
            passed[elem]=true;
            res= find_component(res,(char)(elem+'A'));
        }
    }
    return res;
}

int main(){
    int n;cin>>n;
    set<int> edges;
    for(int i=0;i<n;i++){
        char a,b;
        cin>>a>>b;
        edges.insert(c(a));
        edges.insert(c(b));
        m[c(a)].push_back(c(b));
        m[c(b)].push_back(c(a));
    }
    n=edges.size();
    for(int k : edges){
        if(!passed[k]){
            cout<<find_component("",'A'+k)<<endl;
        }
    }

}
/*
 3
 A B
 C D
 D E

 */