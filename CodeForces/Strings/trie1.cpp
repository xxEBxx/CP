#include<bits/stdc++.h>

using namespace std;
struct TrieNode
{
    map<char,TrieNode*> children;
    int prefixes;
    bool endofword;
    TrieNode()
    {
        prefixes=0;
        endofword=false;
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
    current->endofword=true;
}
bool search(TrieNode *root,string word)
{
    TrieNode *current=root;
    for(int i=0;i<word.size();i++)
    {
        char ch=word[i];
        TrieNode *node=current->children[ch];
        if(!node)
            return false;
        current=node;
    }
    return current->endofword;
}
int count_prefix(TrieNode *root,string word)
{
    TrieNode *current=root;
    for(int i=0;i<word.size();i++)
    {
        char ch=word[i];
        TrieNode *node=current->children[ch];
        if(!node)
        {
            return 0;
        }
        current=node;
    }
    return current->prefixes;
}

int res=0,x;
string ban;
void dfs(TrieNode *node,int k){
    if (k>x){res--;return ;}
    for(auto it : node->children){
        res++;
        if(ban[it.first-'a']=='0')dfs(it.second,k+1);
        else dfs(it.second,k);
    }
}

int main()
{
    TrieNode *head=new TrieNode();
    string word;cin>>word>>ban;
    cin>>x;
    int n=word.size();
    for(int i=0;i<n;i++){
        string to_insert="";
        for(int j=i;j<n;j++){
            to_insert+=word[j];
        }
        insert(head,to_insert);
    }
//now our trie is made , we need to do dfs
// and break if we find problems more than k or so
    dfs(head,0);
    cout<<res;
    return 0;
}