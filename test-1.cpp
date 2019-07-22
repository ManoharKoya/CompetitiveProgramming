#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define pb push_back
#define pr pair<lli,lli>
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;
int solve(){
    lli n,m; cin>>n>>m;
    vector<vector<pr>> pv,pv1;
    pv.resize(n); pv.resize(m);
    pv1.resize(n); pv1.resize(m);
    NA(i,0,n){
        NA(j,0,n){
            cin>>pv[i][j].first; pv[i][j].second==j+1;
            cin>>pv1[i][j].first; pv1[i][j].second==j+1;
        }
    }
    NA(i,0,n) sort(pv[i].begin(),pv[i].end());
    lli ah[n][m],av[n][m];
    
    return ;
}
int main(){
    lli t; cin>>t;
    NA(i,0,n) solve();
    return 0;
}