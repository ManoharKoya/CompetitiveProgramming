#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define KING 1000000002
#define queen 1000002
#define fi first
#define se second
#define se second
#define nl cout<<'\n'
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

vi gp[100005], bit(100005, 1);
lli n,a,b,k,root,similar=0; 

void bit_u(lli nd, lli val){
    while(nd<=n) 
        bit[nd] += val, nd += (nd & -nd);
    return;
}
lli bit_q(lli a, lli b){
    lli res = 0;
    // upto(a) - upto(b-1)
    while(b>0) res += bit[b], b -= (b & -b);
    a--;
    while(a>0) res -= bit[a], a -= (a & -a);
    return res;
}
void dfs(lli nd){
    similar += bit_q(max((lli)1,nd-k), min(nd+k, n));
    // cout<<nd<<"->"<<similar<<'\n';
    bit_u(nd, 1); // opening 
    for(lli i:gp[nd]) dfs(i); // all in between will have nd as parent. (only shild of nd have nd as par.)
    bit_u(nd, -1); // closing 
}
void solve(){
    cin>>n>>k;
    NA(i,0,n-1) cin>>a>>b , gp[a].pb(b), bit[b] = 0;
    NA(i,1,n+1) if(bit[i]) root = i, bit[i]=0;
    // cout<<root<<'\n';
    dfs(root);
    cout<<similar;
    return;
}
int main(){
    fastIO;
    lli t=1; 
    // cin>>t; 
    NA(i,0,t) solve();
    return 0;
}