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
#define Pi 3.141592653589793238
#define nl cout<<'\n'
#define TEST cout<<"TEST",nl
#define all(a) a.begin(), a.end()
#define remax(a, b) (a = ((a<b) ? b : a))
#define remin(a, b) (a = ((a<b) ? a : b))
#define pr pair<lli,lli>
#define pb push_back
#define eb emplace_back
#define precise(a) cout<<fixed<<setprecision(a)
#define mp make_pair
#define vi vector<lli>
#define vpi vector<pr> 
#define P pair<lli,pr>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;

lli const N = 1e5 + 1;
lli n,k;
lli dp[12][N] = {0};

void update(lli *p, lli pos, lli val){
	for(;pos<N;pos+=lsb(pos)) p[pos]+=val;
	return;
}
lli query(lli *p, lli pos){
	lli res = 0;
	for(;pos>0;pos-=lsb(pos)) res+=p[pos]; 
	return res;
}

void solve(){
	cin>>n>>k;
	while(n--){
		lli x; cin>>x;
		for(lli i=11; i>0; --i)
			update(dp[i], x, query(dp[i-1], x)); 
			// quer(dp[i-1], x) will give pref_sum = no. of q's < x with subseq length = i ending at q.
		update(dp[0], x, 1); // with subseq len = 1
	}	
	cout<<query(dp[k], N-1);
	return;
}

int main(){
	fastIO;
	lli t = 1;
	// cin>>t;
	NA(i,0,t){ 
		// cout<<"case #"<<i+1<<": ";
		solve();
	}
	return 0;
}
