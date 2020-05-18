#include<bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

struct block{
    int x,y,t;
};

char a[25][25];
int ans = 0;
int d[4][2] = {1,0,0,-1,0,1,-1,0}, n,m;

void bfs(int x, int y){
    queue<block> q;
    block b; b.x = x, b.y = y, b.t = 0;
    vector<vector<bool> > vis(25, vector<bool> (25, 0));
    vis[x][y]=1;
    q.push(b);
    while(!q.empty()){
        block tp = q.front(), newb; 
        q.pop(); 
        for(int i=0; i<4; ++i) {
            newb.x = tp.x+d[i][0], newb.y = tp.y + d[i][1], newb.t = tp.t + 1;
            if(newb.x>=0 && newb.x<n && newb.y>=0 && newb.y<m && a[newb.x][newb.y]=='.' && !vis[newb.x][newb.y])
                ans = max(ans, newb.t),
                q.push(newb),
                vis[newb.x][newb.y] = 1;
        }
    }
    return;
}
int main(){
    fastIO;
    cin>>n>>m;
    for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) cin>>a[i][j];
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(a[i][j]=='.') bfs(i,j);
        }
    }
    cout<<ans;
    return 0;
}