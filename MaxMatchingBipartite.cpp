#include<bits/stdc++.h>
#define NA(i,s,n) for(int i=s;i<n;i++)
#define pb push_back
#define MN 1001
using namespace std;
// just a combination of Bipartite and maxFlow codes..
int cap[MN][MN], cur[MN][MN], n1, n2, m, a, b, s, t;
vector<int> gp[MN];

void reConstructGraph(){
    NA(i,1,n1+n2+1){
        for(int j: gp[i]){
            if(i<=n1) cap[i+1][j+1]=1; // node-1 as 2 and node-2 as 3 and so on..
            else cap[j+1][i+1]=1; 
        }
    }
    s = 1, t = n1+n2+2;
    // adding s, t to gp..
    NA(i,2,n1+2) cap[1][i]=1;
    NA(i,n1+2,n1+n2+2) cap[i][n1+n2+2]=1; 
    return;
}
vector<int> bfsAugpath(int node){
    vector<int> res, prev(n1+n2+3,0);
    vector<bool> vis(n1+n2+3,0);
    queue<int> q; q.push(node); 
    prev[node]=0; 
    int f;
    while(!q.empty()){
        f = q.front(); q.pop();
        if(f==t) break;
        vis[f] = 1;
        NA(i,1,n1+n2+3) if( !vis[i] && cap[f][i]-cur[f][i] > 0) q.push(i), prev[i]=f;
    }
    if(f!=t) return res;
    int i=t; res.pb(t);
    while(prev[i]!=0) {
        res.pb(prev[i]);
        i = prev[i];
    }
    int bottleNeck = 1e5;
    NA(i,0,res.size()-1) bottleNeck = min(bottleNeck, cap[prev[res[i]]][res[i]]-cur[prev[res[i]]][res[i]]); 
    reverse(res.begin(),res.end());
    res.pb(bottleNeck); // bottleNeck is appended to the vector.
    return res;
}
void updateBottle(int bn, vector<int> path){
    NA(i,0,path.size()-1){
        a = path[i], b = path[i+1];
        assert(cur[a][b]+bn <= cap[a][b]);
        cur[a][b]+=bn;
        cur[b][a]-=bn; // updating inverse path.
    }
    return;
}
int main(){
    NA(i,0,MN+1) NA(j,0,MN) cap[i][j]=cur[i][j]=0;

    cin>>n1>>n2>>m;
    // 1 - n1 boys/red/employees, n1+1 - n2 girls/blue/jobs.
    NA(i,0,m){
        cin>>a>>b;
        gp[a].pb(b);
    }
    
    reConstructGraph();
    
    int maxMatching=0;
    
    while(true){
        vector<int> augPath = bfsAugpath(s);
        if(!augPath.size()) break; 
        int bottleNeck = augPath[augPath.size()-1];
        augPath.pop_back(); 
        updateBottle(bottleNeck, augPath);
        maxMatching += bottleNeck;

        cout<<"connection -> "; cout<<augPath[1]-1<<' '<<augPath[augPath.size()-2]-1<<'\n';
    }
    cout<<maxMatching;
    return 0;
}