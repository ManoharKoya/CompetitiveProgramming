#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define KING 1000000002
#define queen 1000002
#define fi first
#define se second
#define nl cout<<"\n"
#define TEST cout<<"TEST",nl
#define pr pair<lli,lli>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define vi vector<lli>
#define vpi vector<pr> 
#define P pair<lli,pr>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;
/*
  complexity analysis.. 
    insertion O(n) n-length of string.
    searching O(n) n-length of string.
*/
struct trie{
  struct trie *cld[26];
  bool EndofStr;
};
struct trie* getTrie(){
  struct trie *t = new trie;
  t->EndofStr = false;
  NA(i,0,26) t->cld[i]=NULL;
  return t;
}
void insert(struct trie* root, string s){
  struct trie* f = root;
  int ind;
  NA(i,0,s.length()){
    ind = s[i]-'a';
    if(!f->cld[ind]) f->cld[ind]=getTrie();
    f = f->cld[ind];
  }
  f->EndofStr = true;
  return;
}
bool search(struct trie* root, string s){
  struct trie* f = root;
  int ind;
  NA(i,0,s.length()){
    ind = s[i]-'a';
    if(!f->cld[ind]) return false;
    f = f->cld[ind];
  }
  return (f!=NULL && f->EndofStr);
}
int main(){
  struct trie *root = getTrie();
  int q,p; cin>>q; string s;
  NA(i,0,q){
    cin>>p>>s;
    if(p) insert(root,s);
    else {
      if(search(root,s)) cout<<"Exists\n";
      else cout<<"No\n";
    } 
  }
  return 0;
}