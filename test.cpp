#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define KING 1000000000
#define pr pair<lli,lli>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define vi vector<lli>
#define vpi vector<pr> 
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;
struct seg{
    seg *r;
    seg *l;
    lli sm,a,b; 
};
void construct(seg *root,lli s,lli n){
    struct seg *l = (struct seg*)malloc(sizeof(struct seg));
    struct seg *r = (struct seg*)malloc(sizeof(struct seg));
    l->a = s; l->b=n/2; r->a=(n/2)+1; r->b=(n); l->sm=0; r->sm=0;
    r->l=NULL;l->l=NULL; r->r=NULL; l->r=NULL;
    root->l = l; root->r = r;
    construct(l,s,n/2);
    construct(r,(n/2)+1,n);
    return ;
}
void solve(){
    lli n; cin>>n;
    struct seg *rt = (struct seg*)malloc(sizeof(struct seg));
    rt->a=0;rt->b=n-1;rt->sm=0; rt->l=NULL; rt->r=NULL; 
    construct(rt,n);
    return;
}
int main(){
    fastIO; 
    lli t; cin>>t;
    NA(i,0,t) solve();
    return 0;
}