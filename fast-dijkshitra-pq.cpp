#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define KING 100000000002
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
    fast Dijkshihtra impl -> priorityQueue.
    
    Idea:   -> initialize d[i]=KING.
            -> select v by min.d[v] until all nodes are selected.
            ->      select only if d[pq.top().fi]==pq.top().se 
            -> try to relax all nodes adj to currentSeln. (update d[i])
            -> if(relaxed): push {i,d[i]} to pq.
    
    expected - O(N.logN)
    original(normal dijkshitra) - O(N.N)
    
    ex.input/output:
    4 4
    1 2 3
    2 3 4
    3 4 5
    1 3 3
    1
    output:
    0 3 3 8
*/
vector<pr> gp[queen];   // directed graph.
priority_queue<pr > pq; 
lli n,m,a,b,c,ct;
vi d;                   // dist's from a given single sourece. 
vector<bool> vis;

void solve(){
	cin>>n>>m; 
    NA(i,0,m) {
        cin>>a>>b>>c;
        gp[a].pb({b,c}); 
    }
    d.resize(n+1,KING); vis.resize(n+1,false);
    cin>>c; // single source.
    NA(i,0,gp[c].size()) pq.push({-gp[c][i].se,gp[c][i].fi}),d[gp[c][i].fi]=(gp[c][i].se);
    ct=0; vis[c]=1; d[c]=0;
    while(ct<n && !pq.empty()){
        a = pq.top().se; b = (-pq.top().fi);    
        if(vis[a]) continue;
        ct++, vis[a]=true;
        // relax all adj to a;
        for(auto i:gp[a]){
            // cout<<'('<<i.fi<<','<<i.se<<')',nl;
            if(d[i.fi]>(d[a]+i.se)) 
                d[i.fi]=(d[a]+i.se),
                pq.push({-d[i.fi],i.fi});
        }
        pq.pop();
    }
    NA(i,1,n+1) cout<<d[i]<<" ";
	return;
}
int main(){
    fastIO; 
	lli q; q=1;
    NA(i,0,q) solve();
    return 0;
}
