#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define KING 1000000000
#define queen 1000009
#define nl cout<<endl
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
    max sum path form root to leaf.
    1 is always root of the tree give. plz follow the constraint.
*/
vi dp;
void dfs(lli a,lli rt,vi gp[],vi wts){
    lli mx=0; dp[a]=wts[a];
    NA(i,0,gp[a].size()){
        lli child = gp[a][i];
        if(child==rt) continue;
        dfs(child,a,gp,wts);
        mx = max(mx,dp[child]);
    }
    dp[a]+=mx;
    return;
}
void solve(){
    lli n,m,a,b; cin>>n>>m;
    vi gp[n+1],wts; wts.resize(n+1); dp.resize(n+1);
    // gp created.
    NA(i,0,m) cin>>a>>b, gp[a].pb(b),gp[b].pb(a);
    NA(i,0,n) cin>>wts[i+1];
    // dfs
    dfs(1,0,gp,wts);
    cout<<dp[1]<<"\n";
	return;
}
int main(){
	fastIO; solve();
    return 0;
}