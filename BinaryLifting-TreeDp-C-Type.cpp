#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define KING 1000000000
#define queen 1000009
#define nl cout<<"\n"
#define pr pair<lli,lli>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define vi vector<lli>
#define vpi vector<pr> 
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;

/*
    finding LCA - 1 tree q queries 
        prec -> O(N.logN)-once for a tree, 
        queryc -> O(logN)-once for a query.  
    finding path length between 2 nodes. -> O(logN) 
    finding kth parent of a node. -> O(logN)
*/

const long N =1e5+1,lg=30;

lli n,p[N][30]; 
vi gp[N],lvl;

void dfs(lli a,lli rt){
    lvl[a]=lvl[rt]+1;
    p[a][0]=rt;
    for(lli i:gp[a]){
        if(i==rt) continue;
        dfs(i,a);
    }
    return;
}

lli lca(lli u,lli v){
    if(lvl[u]<lvl[v]) swap(u,v);
    // equate lvl of u to v
    lli tlg=log2(lvl[u]);
    for(lli i=tlg;i>=0;i--){
        if(lvl[u]-(1<<i) >= lvl[v]){
            u = p[u][i];
        }
    }
    if(u == v) { cout<<"lca -> "<<v,nl; return v;}

    for(lli i=tlg;i>=0;i--){
        if(p[u][i]!=-1 && p[u][i]!=p[v][i]){
            u = p[u][i],v=p[v][i];
        }
    }
    cout<<"lca -> "<<p[u][0],nl;
    return p[u][0];
}
lli dist(lli u,lli v){
    lli res = lvl[u]+lvl[v]-(2*lvl[lca(u,v)]);
    cout<<"dist -> "<<res,nl;
    return res;
}
lli kthPar(lli u,lli k){
    // k = lvl[u]-k;
    lli tlg = log2(lvl[u]);
    for(lli i=tlg; i>=0;i--){
        if(k==0) break;
        if(k>=(1<<i)){
            k-=(1<<i);
            u = p[u][i];
        }
    }
    cout<<"kth parent -> "<<u,nl;
    return u;
}
void solve(){
    lli a,b; cin>>n;
    lvl.resize(n+1);
    NA(i,1,n){
        cin>>a>>b; 
        gp[a].pb(b),gp[b].pb(a);
    }
    NA(i,0,n+1) NA(j,0,30) p[i][j]=-1;
    lvl[0]=-1;
    dfs(1,0);
    // parents of all-n at 2^k dist.
    NA(i,1,30){
        NA(j,1,n+1){
            if(p[j][i-1]!=-1)
            p[j][i] = p[p[j][i-1]][i-1];
        }
    }

    lli q; cin>>q;
    NA(i,0,q)
        cin>>a>>b,dist(a,b);
        
    // cin>>a>>b; kthPar(a,b);
    return;
}
int main(){
    solve();
    return 0;
}
