#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define pb push_back
#define pr pair<lli,lli>
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;
void bfs(lli r,vector<lli> gp[], lli vis[]){
    lli cur;
    queue<lli> q;
    q.push(r); vis[r]=1;
    while(!q.empty()){
        cur = q.front();
        cout<<cur<<" ";
        q.pop();
        vector<lli>::iterator it = gp[cur].begin();
        while(it!=gp[cur].end()){
            if(vis[*it]==0) {
                q.push(*it); vis[*it]=1;
            }
            it++;
        }
    }
    return; 
}
void ptGp(vector<lli> gp[], lli v){
    NA(i,1,v+1){
        auto itr = gp[i].begin();
        cout<<i<<"->";
        while(itr!=gp[i].end()){
            cout<<*itr<<" "; itr++;
        }
        cout<<endl;
    }
}
int main(){
    //Store graph --> this is a directed graph storage.
    lli v,e,a,b; cin>>v>>e; //no. of nodes, edges
    vector<lli> gp[v+1];
    NA(i,0,e){
        cin>>a>>b;
        gp[a].push_back(b);
       // gp[b].push_back(a); // adding for bidirectional.
    }
    //print gp.
    //ptGp(gp,v);
    // created visited array.
    lli vis[v+1];
    NA(i,1,v+1) vis[i]=0;
    // bfs
    lli r;
    cout<<"Enter root: ";
    cin>>r;
    bfs(r,gp,vis);
    return 0;
}