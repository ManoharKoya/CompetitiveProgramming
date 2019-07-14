#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define pb push_back
#define pr pair<lli,lli>
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;
// struct node{
//     lli val;
//     struct node* next;
// };
// struct node *root=NULL;
// struct node *temp=NULL;
// struct node cnode(lli v){
//     struct node *n;
//     n = (struct node*)malloc(sizeof(struct node));
//     n->val = v;
//     n->next = NULL;
//     return n;
// }
// void createCLL(lli n){
//     lli v; 
//     cin>>v;
//     root = (struct node*)malloc(sizeof(struct node));
//     root->val=v;
//     root->next = NULL;
//     temp = root;
//     NA(i,0,n-1){
//         cin>>v; 
//         temp->next = cnode(v);
//         temp=temp->next;
//     }
//     temp->next = root;
// }
// void printCLL(){
//     temp=NULL;
//     while(){

//     }
// }
// void solve(){
//     lli n; cin>>n;
//     createCLL(n);   
// }
// int main(){
//     string s; cin>>s;
//     lli n; cin>>n;
//     NA(i,0,n) solve();
// }
bool isPrime(lli num){
    bool flag=true;
    for(lli i = 2; i <= num / 2; i++) {
       if(num % i == 0) {
          flag = false;
          break;
       }
    }
    return flag;
}

int main(){
    lli m = 999950884;
    NA(i,m+1,10e9+1){
        if(isPrime(i)) cout<<i<<endl;
    }
    return 0;
}