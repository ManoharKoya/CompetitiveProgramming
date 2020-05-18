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
#define NINF -1e16
#define INF 1e16
#define queen 1000002
#define fi first
#define se second
#define se second
#define lsb(i) (i & -i)
#define nl cout<<'\n'
#define TEST cout<<"TEST",nl
#define pr pair<lli,lli>
#define remax(a, b) (a = ((a<b) ? b : a))
#define remin(a, b) (a = ((a<b) ? a : b))
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define vi vector<lli>
#define vpi vector<pr> 
#define P pair<lli,pr>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;

const lli N = 1e6+1;
lli f[N], t, n, q; 
void add(lli p, lli val){
	for(;p<=n;p+=lsb(p)) f[p]+=val;
	return;
}
lli query(lli p){ // sum upto p..
	lli ans = 0;
	for(;p>=1; p-=lsb(p)) ans += f[p];
	return ans;
}
lli findMe(lli sm){
	lli l = 1, r = n, res;
	while(r<=l){
		lli mid = (r+l)/2;
		if(query(mid)>=sm) res = mid, r = mid-1;
		else l = mid+1;
	}
	return res;
}
void solve(){
	cin>>n>>q;
	memset(f, 0LL, sizeof(f));
	NA(i,0,n) cin>>t, add(t, 1);
	while(q--){
		cin>>t;
		if(t>0){
			// simple update..
			// ++f[t]; 
			add(t, 1);
		} else {
			// delete t'th order statistic..
			t*=(-1);
			lli pos = findMe(t);
			add(pos, -1);
		}
	}
	if(query(n+1)) {
		
	} else {
		cout<<0<<'\n';
	}
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
