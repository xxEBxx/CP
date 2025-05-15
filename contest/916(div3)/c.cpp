#include<iostream>
using namespace std;

struct node {
    int data;
    node* d;
    node* g;
    
    // Constructor to initialize pointers
    node() {
        d = nullptr;
        g = nullptr;
    }
};

void creategraph(node* root,int * a,int *b,int n, int k,char c){
    
    root->data= (c=='d')? a[0] : b[0];
    node droit ;
    node gauche;
    root->d=new node();
    root->g=new node();

    if(k == 1){
        root->d->data=a[1];
        root->g->data=b[0];
        return;
    }
    creategraph( root->d , a+1 ,b+1,n-1,k-1 ,'d');
    creategraph( root->g , a , b,n-1,k-1 ,'g');

}

void printTree(node* root, int depth = 0, char prefix = ' ') {
    if (root == nullptr) {
        return;
    }

    // Print the right subtree
    printTree(root->d, depth + 1, 'd');

    // Print the current node
    for (int i = 0; i < depth; i++) {
        cout << "    ";
    }
    cout << prefix << "--> " << root->data << endl;

    // Print the left subtree
    printTree(root->g, depth + 1, 'g');
}

int max(node *root, int k) {
    if (root == NULL) {
        return 0;
    }
    
    int leftSum = max(root->g, k - 1);
    int rightSum = max(root->d, k - 1);

    int currentSum = root->data + max(leftSum, rightSum);

    
    // If k becomes 0, return 0 (since we don't want to explore further)
    if (k == 0) {
        return 0;
    }
    
    return currentSum;
}
int maxarr(int *b,int n){
    int max=b[0];
    for (int i=1;i<n;i++){
        if (b[i]>max) {
            max=b[i];
        }
    }
    return max;
}
int main (){
    int t=1;
    cin>>t;
    for (int tp=0;tp<t;tp++){
        int n,k,value;
        cin>>n;
        cin>>k;
        int a[n]={1,2,3},b[n]={4,5,6};
        int count;
        for (int i=0;i<n;i++){
            cin>>value;
            a[i]=value;
        }
        for (int i=0;i<n;i++){
            cin>>value;
            b[i]=value;
        }
        node root;
        if (k<n){
        creategraph(&root ,a,b,n,k,'d');
        cout << max(&root,k);
        }
        else {
        creategraph(&root ,a,b,n,n,'d');
        int d=k/n;
        cout<< max(&root,n)*d + max(&root,k-n*d); 
        }
        printTree(&root);
        cout<<endl<<max(&root,k)<<endl;
    }
    
}