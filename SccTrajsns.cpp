#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define NA(i,s,n) for(int i=s;i<n;++i)
vector<int> gp[101], vis, seenStack, lowLink, ids;
stack<int> stk;
int n,m,a,b,id=1;

void dfs(int nd){
    seenStack[nd]=1, stk.push(nd), vis[nd]=1, ids[nd]=lowLink[nd]=id++;
    for(int i: gp[nd]) {
        if(vis[i]) continue;
        dfs(i);
        if(seenStack[nd]) lowLink[i]=min(lowLink[i], lowLink[nd]);
    }
    if(lowLink[nd]==ids[nd]) {
        while(!stk.empty()) {
            int tp = stk.top(); 
            stk.pop(); seenStack[tp]=0;
            lowLink[tp]=ids[nd]; //cout<<"done..\n";
            if(tp==nd) break;
        }
    }
    return;
}
int main(){
    cin>>n>>m; vis.resize(n+1,0), seenStack.resize(n+1,0), lowLink.resize(n+1,0), ids.resize(n+1,0);
    NA(i,0,m) cin>>a>>b, gp[a].pb(b);  
    NA(i,1,n+1) if(!vis[i]) dfs(i); 
    NA(i,1,n+1) cout<<lowLink[i]<<' ';
    return 0;
}