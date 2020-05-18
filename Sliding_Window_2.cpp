#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define KING 1000000002
#define queen 1000002
#define fi first
#define se second
#define se second
#define nl cout<<'\n'
#define TEST cout<<"TEST",nl
#define pr pair<lli,lli>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define vi vector<lli>
#define vpi vector<pr> 
#define P pair<lli,pr>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;
/*
    Sliding_window_2 :
        find all substrs of A which are permutations of str B.
*/
void solve(){
    string a,b; 
    cin>>a>>b;
    lli k = b.size(), n = a.size();
    assert(n >= k);
    vi cnt(26, 0), org(26, 0), res; 
    NA(i,0,k) cnt[a[i]-'a']++, org[b[i]-'a']++;
    NA(i,0,26) if(cnt[i]!=org[i]) break; else if(i==25) res.pb(0);
    NA(i,1,n-k+1){
        cnt[a[i]-'a']--, cnt[a[i+k-1]-'a']++;
        NA(j,0,26) if(cnt[j]!=org[j]) break; else if(j=
        =25) res.pb(i);
    }
    for(lli i:res) cout<<i+1<<" ";
    return;
}  
int main(){
    fastIO;
    lli t; cin>>t; 
    while(t--) solve();
    return 0;
}