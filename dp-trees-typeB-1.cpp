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
    finding height of the tree from all possible nodes as roots.
*/

const long N = 1e5;
vi dp,in,out,gp[N];

void inDFS(lli a,lli rt){
    in[a]=0;
    NA(i,0,gp[a].size()){
        lli val = gp[a][i];
        if(val==rt) continue;
        inDFS(val,a);
        in[a] = max(in[a],1+in[val]);
    }
    return;
}
void outDFS(lli a,lli rt){
    lli m1=-1,m2=-1;
    // finding top 2 max values.
    NA(i,0,gp[a].size()){
        lli val = gp[a][i];
        if(val==rt) continue;
        if(in[val]>=m1) m2=m1,m1=in[val];
        else if(in[val]>m2) m2=in[val];
    }

    NA(i,0,gp[a].size()){
        lli val = gp[a][i],use=m1;
        if(val==rt) continue;
        if(in[val]==m1) use=m2;
        out[val] = max(1+out[a],2+use);
        outDFS(val,a);
    }

    return;
}

void solve(){

    lli n,m,a,b; cin>>n>>m; 
    in.resize(n+1),out.resize(n+1),dp.resize(n+1);
    NA(i,0,m) cin>>a>>b,gp[a].pb(b),gp[b].pb(a);
    // exit(0);
    inDFS(1,0); 
    // out[1]=in[1];
    outDFS(1,0);
    // exit(0);
    NA(i,1,n+1) cout<<in[i]<<" ",dp[i]=max(in[i],out[i]),cout<<dp[i]<<endl; 
    nl;
    return;
}
int main(){
	fastIO; solve();
    return 0;
}