#include<bits/stdc++.h>

using namespace std;
struct TrieNode
{
    map<char,TrieNode*> children;
    int prefixes;
    bool can_win=false;
    bool can_lose=false;
    TrieNode()
    {
        prefixes=0;
    }
};
void insert(TrieNode *root,string word)
{
    TrieNode *current=root;
    for(int i=0;i<word.size();i++)
    {
        char ch=word[i];
        TrieNode *node=current->children[ch];
        if(!node)
        {
            node=new TrieNode();
            current->children[word[i]]=node;
        }
        current=node;
        current->prefixes++;
    }
}
void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

void dfs(TrieNode *node){
    if(node->children.empty()){
        node->can_lose=true;
        return ;
    }
    for(auto it : node->children){
        dfs(it.second);
        if(!it.second->can_lose){
            node->can_lose=true;
        }
        if(!it.second->can_win){
            node->can_win=true;
        }
    }
}

int main(){fast();
    int n,k;cin>>n>>k;
    TrieNode *head=new TrieNode();
    for(int i=0;i<n;i++){
        string val;cin>>val;
        insert(head,val);
    }
    dfs(head);

    if(head->can_win && head->can_lose){
        cout<<"First";
    }
    else if(head->can_win){
        if(k&1)cout<<"First";
        else cout<<"Second";
    }
    else if(!head->can_win){
        cout<<"Second";
    }

    return 0;
}