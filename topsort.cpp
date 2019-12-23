#include<bits/stdc++.h>
using namespace std;

vector<int> gp[10000]; 
int n,m;

void dfs(vector<int> &res, int i, vector<bool> &vis){
    for(int a: gp[i]){
        if(vis[a]) continue;
        dfs(res, a, vis);
    }
    if(!vis[i]) res.push_back(i);
    vis[i] = 1;
    return;
}

vector<int> topsort(vector<int> gp[]){
    vector<int> res;
    vector<bool> vis(n+1,0);
    for(int i=1;i<n+1;i++){
        if(vis[i]) continue;
        dfs(res, i, vis);
    }
    return res;
}

int main(){
    cout<<"Enter graph for topSearch..\n     Enter number of nodes and edges..\n";
    cin>>n>>m; int a,b;
    cout<<"     Enter Edges..\n";
    for(int i=0;i<m;i++){
        cin>>a>>b;
        gp[a].push_back(b);
    }
    vector<int> order = topsort(gp);
    cout<<"topological sort order .. "; 
    for(int i=0;i<order.size();i++) 
        (i != order.size()-1) ? cout<<order[i]<<"->" : cout<<order[i];

    return 0;
}