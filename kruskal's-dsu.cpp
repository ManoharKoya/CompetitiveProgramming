#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define KING 1000000002
#define queen 100002
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
bool cmp(lli a,lli b){ return (a>b); }
/*
    Kruskal's impl -> priority queue(edge) -> dsu for chacking cycle .
    
    Idea:   -> select always min edge 
            -> check both the vertices belong to same sub-graph(dsu-group) 
            -> if not push to ans.
            -> terminate if n-1 edges are pushed to ans.
*/
struct dsu{
	lli par[202],sz[202];
	inline void init(lli _n){ NA(i,0,_n) par[i]=i,sz[i]=1;}
	inline lli find(lli now){
		if(par[now]==now) return now;
		return par[now]=find(par[now]);
	}
	inline bool uni(lli a, lli b){
		lli Pa(find(a)),Pb(find(b));
		if(Pa==Pb) return false;
        if(sz[Pa]<sz[Pb]) par[Pa]=par[Pb],sz[Pb]+=sz[Pa];
        else par[Pb]=par[Pa],sz[Pa]+=sz[Pb];
		return true;
	}
};
priority_queue<P> gp;
vector<P> res;
lli n,m,a,b,c,ct; 
void solve(){
	cin>>n>>m;
    NA(i,0,m) cin>>a>>b>>c,gp.push({(-c),{a,b}}); 
    dsu d; d.init(n+1); ct=0;
    while(ct<(n-1)){
        a = gp.top().se.fi, b = gp.top().se.se;
        if(d.find(a)!=d.find(b)){
            ct++, d.uni(a,b), res.pb(gp.top()), gp.pop();
        } else gp.pop();
    }
    NA(i,0,ct) cout<<"("<<res[i].se.fi<<","<<res[i].se.se<<")->"<<(-res[i].fi),nl;
	return;
}
int main(){
    fastIO; 
	lli q; q=1;
    NA(i,0,q) solve();
    return 0;
}