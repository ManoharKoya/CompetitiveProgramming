#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define KING 1000000000
#define queen 1000009
#define nl cout<<endl
#define pr pair<lli,lli>
#define pb push_back
#define eb emplace_back 
#define mp make_pair
#define vi vector<lli>
#define vpi vector<pr> 
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;
/*
    https://codeforces.com/contest/1213/problem/D2
*/
void solve(){
	lli n,k,x,ct,p; cin>>n>>k;
    lli a[n]; NA(i,0,n) cin>>a[i];
    vector<vi> mp(200*1000 + 5);
    NA(i,0,n){
        x=a[i]; ct=0;
        while(x>0){
            mp[x].pb(ct);
            x/=2; ct++;
        }
    }
    lli ans = 1e9;
    NA(i,0,200*1000 + 5){
        if(mp[i].size()>=k) {
            sort(mp[i].begin(),mp[i].end());
            p = accumulate(mp[i].begin(),mp[i].begin()+k,0); 
            ans = min(ans, p);
        }
    }
    cout<<ans;
	return;
}
int main(){
	fastIO;
	solve();
    return 0;
}