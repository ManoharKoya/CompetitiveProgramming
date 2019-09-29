#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define KING 1000000000
#define queen 100002
#define nl cout<<"\n"
#define pr pair<lli,lli>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define vi vector<lli>
#define vpi vector<pr> 
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;
void solve(){
	lli n,q,c,d; cin>>n>>q;
    vi a(n+1),b(n+1);
    NA(i,1,n) cin>>a[i];
    b[1] = a[1], b[0] = 0;
    NA(i,2,n){
        if(i%2) b[i] = b[i-1]+a[i];
        else b[i] = b[i-1]-a[i];
        // cout<<b[i]<<" ";
    }
    NA(i,0,q) {
        cin>>c>>d; // cout<<"("<<c<<","<<d<<")",nl;
        if(!((abs(c-d))%2)) cout<<"UNKNOWN",nl;
        else {
            if(c>d) swap(c,d);
            if(c%2) cout<<b[d-1]-b[c-1],nl;
            else cout<<b[c-1]-b[d-1],nl;   
        }
    }
}
int main(){
	fastIO; 
	lli t; cin>>t; NA(i,0,t) solve();
    return 0;
}