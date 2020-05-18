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

const lli N = 1001001;
vi e(N, 0);
void solve(){
	lli ans = 0,a,b,c,d; cin>>a>>b>>c>>d;
	NA(i,a,b+1) e[i+b]++, e[i+c+1]--; // for getting i in only [b,c] range.. after prefsum
	NA(i,1,N) e[i]+=e[i-1]; // will tell the count of x's can be involved at i.
	NA(i,1,N) e[i]+=e[i-1]; // (x,y) pair count. for sum i.
	NA(i,c,d+1)
		ans += (e[N-1] - e[i]);
	cout<<ans;
	return;
}

int main(){
    fastIO;
    lli t = 1; 
    // cin>>t;
    NA(i,0,t) solve();
    return 0;
}
