#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define pb push_back
#define pr pair<lli,lli>
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;

void dfsRec(lli r,vector<lli> gp[],lli vis[]){
    vis[r]=1; cout<<r<<" ";
    vector<lli>::iterator it=gp[r].begin();
    while(it!=gp[r].end()){
        if(vis[*it]!=1) dfsRec(*it,gp,vis);
        it++;
    }
    return;
}
void dfsItr(lli r, vector<lli> gp[],lli vis[],lli e){
    stack<lli> s; s.push(r);
    lli cur,ct=1;
    while(ct<e+2){
        cur = s.top();
        s.pop();
            cout<<cur<<" ";
        vector<lli>::iterator it = gp[cur].begin();
        while(it!=gp[cur].end()){
            { ct++; s.push(*it); }
            it++;
        }
    }
}
int solve(){
    //store graph.
    lli v,a,b,e; cin>>v>>e;
    vector<lli> gp[v+1];
    lli vis[v+1];
    NA(i,0,v+1) vis[i]=0;
    NA(i,0,e){
        cin>>a>>b; 
        gp[a].pb(b);
    }
    
    cout<<"Enter root: "; lli r; cin>>r;
    // dfsRec(r,gp,vis); cout<<endl;
    // NA(i,0,v+1) vis[i]=0;
    dfsItr(r,gp,vis,e);
}
int main(){
    solve();
    return 0;
}