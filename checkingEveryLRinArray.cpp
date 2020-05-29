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

const lli N = 2e5+1;
lli a[N], l[N], r[N], res[N];

void solve(){
    lli n; cin >> n;
    // find the maximum of minumum strengths for a segment of size k, where forall k in [1,n]
    NA(i,1,n+1) cin >> a[i];
    // l[i] is the left most position such that a[l[i]]>=a[i]
    l[1] = 1;
    NA(i,2,n+1){
        lli j = i;
        while(j>1 && a[j-1]>=a[i]) j = l[j-1];
        l[i] = j;
    }
    // r[i] is right most position such that a[r[i]]>=a[i]
    r[n] = n;
    for(lli i=n-1; i>0; --i){
        lli j = i;
        while(j<n && a[j+1]>=a[i]) j = r[j+1];
        r[i] = j;
    }
    NA(i,1,n+1){
        lli len = r[i] - l[i] + 1;
        remax(res[len], a[i]);
    }
    for(lli i=n; i>0; --i){
        if(res[i] >= res[i-1]) res[i-1] = res[i];
    }
    NA(i,1,n+1) cout << res[i] << ' ';
    return;
}
int main(){
    fastIO;
    lli t = 1; 
    // cin>>t;
    NA(i,0,t){
	//	cout<<"case "<<i+1<<":\n"; 
		solve();
	}
    return 0;
}
