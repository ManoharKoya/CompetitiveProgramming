#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define NA(i,s,n) for(int i=s;i<n;++i)
#define MN 1001
int cap[MN][MN], cur[MN][MN], n, m, a, b, c, s, t;
// cap - capacity, cur - current(present) flow, s-start, t-termination.
vector<int> bfsAugpath(int node){
    vector<int> res, prev(n+1,0);
    vector<bool> vis(n+1,0);
    queue<int> q; q.push(node); 
    prev[node]=0; 
    int f;
    while(!q.empty()){
        f = q.front(); q.pop();
        if(f==t) break;
        vis[f] = 1;
        NA(i,1,n+1) if( !vis[i] && cap[f][i]-cur[f][i] > 0) q.push(i), prev[i]=f;
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

    NA(i,0,MN) NA(j,0,MN) cap[i][j]=cur[i][j]=0;
    cout<<"Enter number of nodes and edges and 's', 't'..\n";
    cin>>n>>m>>s>>t;
    NA(i,0,m) cin>>a>>b>>c, cap[a][b]=c;
    int maxFlow = 0;

    while(true){

        vector<int> augPath = bfsAugpath(s);
        if(!augPath.size()) break; 
        int bottleNeck = augPath[augPath.size()-1];
        augPath.pop_back(); 
        updateBottle(bottleNeck, augPath);
        maxFlow += bottleNeck;

        cout<<"BottleNeck -> "<<bottleNeck<<'\n';
        cout<<"path -> "; NA(i,0,augPath.size()) cout<<augPath[i]<<" "; cout<<'\n';
        
    }

    cout<<"MaxFlow = "<<maxFlow;
    return 0;
}

/*
    Example Output..

Enter number of nodes and edges and 's', 't'..
5 6 1 5
1 2 3
1 3 4
1 4 5
2 5 6
3 5 7
4 5 8
BottleNeck -> 5
path -> 1 4 5
BottleNeck -> 4
path -> 1 3 5
BottleNeck -> 3
path -> 1 2 5
MaxFlow = 12
*/