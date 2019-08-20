#include<bits/stdc++.h>
#define lli long long int
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
void check(vi va,vi vb){
    cout<<va[0]<<" "<<vb[0]<<endl;
    NA(i,0,min(va.size(),vb.size())){
        if(va[i]!=vb[i]) {cout<<va[i-1]<<endl; return;}    
    }
    return;
}
stack<lli> s;
vi va,vb,vis;
void LCSrec(lli r,lli a,lli b,vector<lli> g[],lli n){
    vis[r]=1;
    NA(i,0,g[r].size()){
        if(vis[g[r][i]]!=1){ s.push(g[r][i]); LCSrec(g[r][i],a,b,g,n);}
    }
}
void LCA(lli r,lli a,lli b,vector<lli> g[],lli n){

    stack<lli> s;
    vi va,vb,vis(n+1,0);

    lli c = 0,tp;
    s.push(r);
    while(!s.empty()){
        tp = s.top();
        vis[tp]=1;
        if(tp==a) {
            stack<lli> sa = s;
            while(!sa.empty()) {va.pb(sa.top()); sa.pop();}
            c++; if(c==2) {check(va,vb); break;}
        }
        else if (tp==b){
            stack<lli> sa = s;
            while(!sa.empty()) {vb.pb(sa.top()); sa.pop();}
            c++; if(c==2) {check(va,vb); break;}
        }
        s.pop(); va.pb(tp); vb.pb(tp);
        vi::iterator it = g[tp].begin();
        while(it!=g[tp].end()){
            if(vis[*it]==0) s.push(*it);
            it++;
        }
    }
    return;
}
int main(){
    fastIO;
    lli n,r,q,a,b; cin>>n;
    vector<lli> g[n+1];
    NA(i,1,n){
        cin>>a>>b;
        g[a].pb(b); 
    }
    cin>>q;
    NA(i,0,q){
        cin>>r>>a>>b;
         LCA(r,a,b,g,n);
    }
    return 0;
}

