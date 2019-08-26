/*
    proble link-> https://codeforces.com/problemset/problem/115/A
*/
#include<bits/stdc++.h>
#define lli long long int // change to unsigned int. for some problems. upto 2^64.
#define MOD 1000000007
#define KING 1000000000
#define queen 1000009
#define pr pair<lli,lli>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define vi vector<lli>
#define vpi vector<pr> 
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;
lli bfsLevels(lli r,vi g[],lli n){
    lli lvl[n+1]; vi mkd(n+1,0);
    lli mxl=1;
    queue<lli> q; q.push(r);
    lvl[r]=1;  mkd[r]=1;
    while(!q.empty()){
        lli x = q.front(); q.pop();
        NA(j,0,g[x].size()){
            if(!mkd[g[x][j]]){
                q.push(g[x][j]);
                mkd[g[x][j]]=1; lvl[g[x][j]]=lvl[x]+1; mxl=max(mxl,lvl[g[x][j]]);
            }
        }
    } 
    return mxl;
}
void solve(){
    lli n,t; cin>>n;
    vi g[n+1],roots;
    NA(i,1,n+1){
        cin>>t; if(t==-1) roots.pb(i);
        else {
            g[i].pb(t); g[t].pb(i);
        }
    }
    // bfs to all roots -> levels -> print max of all levels.
    lli mx=0;
    NA(i,0,roots.size()) mx = max(mx,bfsLevels(roots[i],g,n));
    cout<<mx;
    return;
}
int main(){
    fastIO;
    solve();
    return 0;
}

