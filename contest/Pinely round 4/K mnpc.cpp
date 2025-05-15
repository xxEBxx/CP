#include<bits/stdc++.h>


using namespace std;
struct TrieNode{
    map<char,TrieNode*> children;
    int repeated;
    TrieNode(){
        repeated=0;
    }
};
void insert(TrieNode *root,string word){
    TrieNode *current=root;
    for(int i=0;i<word.size();i++){
        char ch=word[i];
        TrieNode *node=current->children[ch];
        if(!node){
            node=new TrieNode();
            current->children[word[i]]=node;
        }
        node->repeated ++;
        current=node;
        //cout<<current->repeated;
    }
}
int search(TrieNode *root,string word){
    TrieNode *current=root;
    for(int i=0;i<word.size();i++){
        char ch=word[i];
        TrieNode *node=current->children[ch];
        if(!node)
            return 0;
        current=node;
    }
    return current->repeated;
}

int main()
{
    TrieNode *root=new TrieNode();
    int n,q;cin>>n>>q;
    vector<string> to_search;
    for(int i=0;i<n;i++){
        string in;cin>>in;
        insert(root,in);
    }
    for(int i=0;i<q;i++){
        string in;cin>>in;
        cout<<search(root,in)<<endl;
    }

    return 0;
}


