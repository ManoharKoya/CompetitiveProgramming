#include<bits/stdc++.h>
using namespace std;
 
struct node{
    int val;
    struct node* right;
    struct node* left;
};
struct node* newNode(int val){
    struct node* tp = new node;
    tp->val = val;
    tp->right = NULL, tp->left = NULL;
    return tp;
}
struct node* insert(struct node* nd, int val){
    if(nd==NULL) return newNode(val);
    if(nd->val < val) nd->right = insert(nd->right, val);
    else nd->left = insert(nd->left, val);
    return nd;
}
void in_order(struct node* root){
    if(root==NULL) return;
    in_order(root->left);
    cout<<root->val<<' ';
    in_order(root->right);
    return;
}
struct node* createTree(vector<int> a, int n){
    struct node* root = NULL;
    root = insert(root, a[0]);
    for(int i=1; i<n;++i) insert(root, a[i]);
    return root;
}
void solve(){
    int n; cin>>n;
    vector<int> a(n); 
    for(int i=0; i<n; ++i) cin>>a[i];
    struct node* root = createTree(a,n);
    in_order(root);
}
int main(){
    solve();
    return 0;
}