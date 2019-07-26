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

void solve(){
    fastIO;
    lli n,b,c,d1,d2,d3,d4; cin>>n;
    vpi a; a.resize(n);
    vpi desc; desc.resize(n);
    NA(i,0,n){
        cin>>b>>c; 
        a[i].first = b; a[i].second = c;
        cin>>d1>>d2>>d3>>d4; 
        desc[i].first=0; desc[i].second=0;
        
    }
    return ;
}
int main(){
    fastIO; 
    lli t; cin>>t;
    NA(i,0,t) solve();
    return 0;
}