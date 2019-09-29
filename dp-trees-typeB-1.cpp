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

const long N = 1e4;
vi in,out;

void inDFS(lli a,lli rt,vi gp[]){
    in[a]=0;
    NA(i,0,gp[a].size()){
        lli val = gp[a][i];
        if(val==rt) continue;
        inDFS(val,a,gp);
        in[a] = max(in[a],1+in[val]);
    }
    return;
}
void outDFS(lli a,lli rt,vi gp[]){
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
        outDFS(val,a,gp);
    }

    return;
}

void solve(){
    lli mx=-2,n,a,b; cin>>n; n++;
    vi gp[N];
    in.resize(n+1,0),out.resize(n+1,0);
    // NA(i,0,m) cin>>a>>b,gp[a].pb(b),gp[b].pb(a);
    NA(i,0,n){
        a = i - (i&(-i));
        ++a,++i; 
        if(i==a) {--i; continue;}
        gp[a].pb(i),gp[i].pb(a); i--;
    }
    // exit(0);
    inDFS(1,0,gp); 
    // out[1]=in[1];
    outDFS(1,0,gp);
    // exit(0);
    NA(i,1,n+1) cout<<in[i]<<" "; nl;
    // NA(i,1,n+1) mx=max(mx,max(in[i],out[i]));
    // cout<<mx,nl; 
    return;
}
int main(){
	fastIO; 
    lli t; cin>>t;
    NA(i,0,t) solve();
    return 0;
}