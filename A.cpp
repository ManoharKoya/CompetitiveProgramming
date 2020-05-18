/********************************
*** ******** ********** *********
*** * ****** ********* * ********
*** ** ***** ******** *** *******
*** *** **** ******* ***** ******
*** **** *** ****** ******* *****
*** ***** ** ***** +++++++++ ****
*** ****** * **** *********** ***
*** *******  *** ************* **
*** ******** ** *************** *
**********_**********************
* |   /  / \  \     /    /\     *
* |  /  |   |  \   /    /  \    *
* | /   |   |   \ /    /    \   *
* |+\   |   |    |    /______\  *
* |  \  |   |    |   |        | *
* |   \  \_/     |   |        | *
********************************/
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
#define all(a) a.begin(), a.end()
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

lli power(lli x,lli y,lli p) { 
	lli res = 1;	 
	x = x % p; 
	while (y > 0) 
	{ 
		if (y & 1) 
			res = (res*x) % p; 
		y = y>>1; 
		x = (x*x) % p; 
	} 
	return res; 
} 

void solve(){
    string s; cin>>s;
	lli p = s.size();
	vpi a = {{s[0]-'0', 1}}; NA(i,1,p) {
		if(a.back().fi == s[i]-'0') a.back().se++;
		else a.pb({s[i]-'0', 1});
	} 
	lli n = a.size(), ans = 1e10;
	NA(i,0,n-2){
		if(a[i].fi!=a[i+1].fi && a[i+1].fi!=a[i+2].fi && a[i].fi!=a[i+2].fi) 
			ans = min(ans, 2+a[i+1].se);
	}
	if(ans==1e10) ans = 0;
	cout<<ans<<'\n';
	return;
}

int main(){
    fastIO;
    lli t = 1; 
    cin>>t;
    NA(i,0,t){
		// cout<<"case #"<<i+1<<": "; 
		solve();
	}
    return 0;
}
