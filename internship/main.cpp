#include<bits/stdc++.h>
#define NA(i,s,n) for(int i=s; i<n; ++i)
using namespace std;

vector<int> gp[100001]; int n,mx;
vector<int> colors,belowColors[100001];
vector<bool> vis;
unordered_set<int> over;

void updateColors(int node, int child){
    for(int i=1; i<=mx; ++i) belowColors[node][i] += belowColors[child][i];
    return;
}
void dfsBelowColors(int node, int par){
    if(vis[node]) return;
    vis[node]=1;
    belowColors[node][colors[node]]++;
    for(int i:gp[node]) if(i!=par && !vis[i]) dfsBelowColors(i, node), updateColors(node, i); 
    return;
}
void fun(int node){
    cout<<"OVER : ";
    for(int i:over) cout<<i<<' ';
    cout<<'\n';
    int special = 0;
    for(int color:over) {
        special += belowColors[node][color];
    } 
    cout<<special<<'\n';
    return;
}
void printBelow(){
    for(int node=1; node<=n; ++node){
        for(int color=1; color<=mx; ++color) cout<<belowColors[node][color]<<' ';
        cout<<'\n';
    }
    return;
}
void solve(){
    int a,b; mx=-1; cin>>n;
    NA(i,0,n-1) cin>>a>>b, gp[a].push_back(b), gp[b].push_back(a);
    vis.resize(n+1,0);
    colors.resize(n+1);
    NA(i,1,n+1) cin>>colors[i], mx=max(mx,colors[i]);
    NA(i,1,n+1) belowColors[i].resize(mx+1,0);
    dfsBelowColors(1,0);
    printBelow();
    int q,node; cin>>q;
    NA(i,0,q) {
        cin>>node;
        over.insert(colors[node]);    
        fun(node);
    }
    return;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}