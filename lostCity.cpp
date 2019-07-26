#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define pr pair<lli,lli>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define vi vector<lli>
#define vpi vector<pr> 
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;
// vector<lli> atLeast(vector<lli> gp[],lli cost[],lli s,lli n){
//     stack<lli> st,mx;
//     vector<lli> all; lli cur;
//     all.resize(n+1,1e9);
//     st.push(s); mx.push(cost[s]);
//     while(!st.empty()){
//         cur = st.top(); st.pop();

//     }
//     return all;
// }
void dfsItr(lli r, vector<lli> gp[],lli cost[],lli e,lli n){
    lli all[n+1];
    NA(i,1,n+1) all[i]=1e9;
    stack<lli> s,mx; s.push(r); mx.push(cost[r]);
    lli cur,curm,ct=1;
    while(ct<e+2){
        cur = s.top(); 
        s.pop();
        curm = mx.top(); // mx.pop();
        // all[cur] = min(all[cur],curm);
    //     vector<lli>::iterator it = gp[cur].begin();
        // while(it!=gp[cur].end()){
        //     { ct++; s.push(*it); mx.push(max(mx.top(),cost[*it])); }
        //     it++;
        // }
        ct++;
    }
    NA(i,1,n+1) cout<<all[i]<<" ";
    return;
}
void solve(){
    //ct
    lli a,b;
    lli n,m,s; cin>>n>>m>>s;
    vector<lli> gp[n+1];
    lli cost[n+1];
    NA(i,1,n+1) cin>>cost[i];
    NA(i,0,m){
        cin>>a>>b; gp[a].pb(b);
    }
    dfsItr(s,gp,cost,m,n);
    return;
}
int main(){
    fastIO; 
    lli t; cin>>t;
    NA(i,0,t) solve();
    return 0;
}