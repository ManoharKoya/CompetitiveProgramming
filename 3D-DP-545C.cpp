#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define KING 1000000002
#define queen 1000002
#define fi first
#define se second
#define se second
#define lsb(i) (i & -i)
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

lli dp[100001][2][2], n; // 0 -right, 1 -left.
vpi a;

lli fun(lli pos, lli prev, lli cur){ 
	// if prevsOne NoCut / left --> prev = 0;
	// else prev = 1;
	if(pos>=n) return 0;
	if(pos==n-1) return cur+1;
	if(dp[pos][prev][cur]!=-1LL) return dp[pos][prev][cur]; 
	lli ans, a1 = 0, a2 = 0, a3 = 0, a4 = 0;
	if(pos==0) {
		a1 = fun(pos+1, 0, 1);
		a3 = a1;
	} else {
		if(prev==0 && a[pos].fi-a[pos].se > a[pos-1].fi){
			a1 = fun(pos+1, 0, 1);
		}
		if(prev==1 && a[pos].fi-a[pos].se > a[pos-1].fi+a[pos-1].se) {
			a3 = fun(pos+1, 0, 1);
		} 
	}
	if(a[pos].fi+a[pos].se < a[pos+1].fi) {
		a2 = fun(pos+1, 1, 1);
	} 
	a4 = fun(pos+1, 0, 0);
	ans = max({a1,a2,a3,a4});
	ans += cur;
	return dp[pos][prev][cur] = ans;
}
void solve(){
	cin>>n;
	a.resize(n); NA(i,0,n) cin>>a[i].fi>>a[i].se;
	memset(dp, -1LL, sizeof(dp));
	cout<<fun(0, 0, 0);
    return;
}
int main(){
    fastIO;
    lli t = 1; 
    // cin>>t;
    NA(i,0,t) solve();
    return 0;
}