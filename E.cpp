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

void solve(){
    lli n,q; cin>>n>>q; vi a(n), pref(n);
    NA(i,0,n) cin>>a[i];
    pref[0] = -a[0]; bool fg = 1;
    NA(i,1,n){
        pref[i] = ((fg) ? (1) : (-1))*a[i] + pref[i-1];
        fg = !fg;
    }
    char c; lli d,b;
    while(q--){
        cin>>c>>d>>b; 
        if(c=='Q'){
            --d, --b;
            if(d-1>-1) cout<<pref[b]-pref[d-1]<<' ';
            else cout<<pref[b]<<' ';
        } else {
            a[d-1] = b;
            pref[0] = -a[0]; fg = 1; 
            NA(i,1,n){
                pref[i] = ((fg) ? (1) : (-1))*a[i] + pref[i-1];
                fg = !fg;
            }
        }
    } nl;
    return;
}

int main(){
    fastIO;
    lli t = 1; 
    cin>>t;
    NA(i,0,t){
         cout<<"Case #"<<i+1<<": ";
         solve();}
    return 0;
}