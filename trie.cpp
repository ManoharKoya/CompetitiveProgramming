// How many numbers x are there in the range a to b, where the digit d occurs exactly k times in x? 
#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define KING 1000000000
#define queen 1000009
#define pr pair<lli,lli>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define vi vector<lli>
#define vpi vector<pr> 
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;
struct trie{
  lli f; bool end;
  trie *children[27];
};
struct trie* root = NULL;
struct trie* newnode(){
  struct trie* t = (struct trie*)malloc(sizeof(struct trie));
  t->f=0; 
  NA(i,0,27) {
      t->children[i] = (struct trie*)malloc(sizeof(struct trie));
      t->children[i]->f=0;
  }
  return t;
}
void insert(string s){
  struct trie *t = root;
  NA(i,0,s.length()-1){
    t->children[s[i]-'a']->f++;
    if(t->children[s[i]='a']->end) 
    t=t->children[s[i]-'a'];
  }
  root->children[s[s.length()-1]-'a']->f+=2;
  return;
}
int main(){
    lli n,q; cin>>n>>q;
    string s;
    root = newnode();
    // NA(i,0,27){
    //   cout<<root->children[i]->f<<" ";
    // }
    NA(i,0,n){
      cin>>s; insert(s);
    }
    NA(i,0,q){
      cin>>s; query(s);
    }
}

