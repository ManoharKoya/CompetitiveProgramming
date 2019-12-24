#include<bits/stdc++.h>
using namespace std;
#define NA(i,s,n) for(int i=s;i<n;++i)
#define pb push_back
#define nl cout<<'\n'
#define MN 1001
int n, m, a, b;
vector<int> gp[MN];
vector<bool> color, vis;

void dfs(int a, bool fg){
    color[a] = fg; vis[a] = 1;
    for(int i: gp[a]) {
        if(vis[i]) {
            assert(color[i]==(!fg));
            continue;
        }
        dfs(i,!fg);
    }
    return;
}

vector<bool> bipartiteDivision(){
    color.resize(n+1,0); vis.resize(n+1,0);
    NA(i,1,n+1) if(!vis[i]) dfs(i,1);
    return color;
}

int main(){
    cout<<"Enter number of nodes and edges..", nl;
    cin>>n>>m;
    NA(i,0,m) cin>>a>>b, gp[a].pb(b);
    vector<bool> color = bipartiteDivision(); 
    NA(i,1,n+1) if(color[i]) cout<<i<<" red\n"; else cout<<i<<" blue\n";
    return 0;
}