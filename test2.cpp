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
lli n,m,s,c,ct;
void solve(){
    cin>>n>>m; //cout<<n<<" "<<m;
    vi a(n,0);
    lli b[m]; //cout<<"TEST",nl;
    NA(i,0,m) cin>>b[i],b[i]--;
    c = 1; ct=0; //cout<<"TEST",nl;
    NA(i,0,m){
        s = b[i];
        ++a[s];
        if(a[s]!=c) {cout<<"NO",nl; return;}
        ct++; if(ct%n==0) ++c;
    }
    cout<<"YES",nl; 
    return;
}
int main(){
	fastIO; 
	lli t; cin>>t; NA(i,0,t) solve();
    return 0;
}