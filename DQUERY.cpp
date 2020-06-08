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


const lli N = 1e6 + 6, M = 3e4 + 4;
lli bit[N] = {0}, a[M], last[N] = {0}, n, q, b, c;
vpi qs[M];

void update(lli pos, lli val){
    for(; pos<N; pos+=lsb(pos)) bit[pos] += val; 
    return;
}

lli query1(lli pos){
    lli res = 0;
    for(; pos>0; pos-=lsb(pos)) res += bit[pos];
    return res;
}

lli query(lli x, lli y){
    lli res = (query1(y) - query1(x-1));
    return res;
}

void solve(){
    lli n; cin >> n;
    NA(i,1,n+1){
        cin >> a[i];
    }
    cin >> q; 
    vi res(q);
    NA(i,0,q){
        cin >> b >> c;
        qs[c].pb({b, i});
    }
    NA(i,1,n+1){
        if(last[a[i]]) update(last[a[i]], -1);
        update(i, 1);
        last[a[i]] = i;
        for(pr j:qs[i]){
            res[j.se] = query(j.fi, i);
        }
    }
    for(lli r:res) cout << r << '\n';
    return;
}

int main(){
    // fastIO;
    lli t = 1;
    // cin>>t;
    NA(i,0,t){
        solve();
    }
    return 0;

}

