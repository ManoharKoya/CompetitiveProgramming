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

lli lcm(lli a,lli b){
    return ((a*b)/__gcd(a,b));
}

const lli N = 2e5 + 5;
vi gp[N];
lli ans = 0, n, a[N], b[N], c[N], d, e, min_a[N];

pr dfs(lli nd, lli rt){
    vi bad_nodes = {0,0};
    if(b[nd]!=c[nd]) bad_nodes[b[nd]]++;
    for(lli i:gp[nd]){
        if(i==rt) continue;
        min_a[i] = min(a[i], min_a[nd]);
        pr p = dfs(i,nd);
        bad_nodes[p.fi] += p.se;
    }
    lli mn = min(bad_nodes[0], bad_nodes[1]);
    ans += (2LL * mn * min_a[nd]);
    bad_nodes[0] -= mn;
    bad_nodes[1] -= mn;
    if(!bad_nodes[0] && !bad_nodes[1]){
        return {0,0}; 
    } else if(!bad_nodes[1]){
        if(rt==0) ans = -1;
        return {0LL, bad_nodes[0]};
    } else {
        if(rt==0) ans = -1;
        return {1LL, bad_nodes[1]};
    }
}

void solve(){
    cin >> n;
    NA(i,1,n+1){
        cin >> a[i] >> b[i] >> c[i];
    }
    NA(i,1,n){
        cin >> d >> e;
        gp[d].pb(e);
        gp[e].pb(d);
    }
    min_a[1] = a[1];
    dfs(1,0);
    cout << ans << '\n';
    return;
}

int main(){
    fastIO; 
    // prec();
    lli t = 1; 
    // cin>>t;
    NA(i,0,t) {
        // cout << "Case #" << i+1 << ": ";
        solve();
        if(i!=t-1) cout << '\n';
    }
    return 0;
}
