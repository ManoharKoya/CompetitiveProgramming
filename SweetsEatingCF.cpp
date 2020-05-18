#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define KING 1000000000
#define queen 100002
#define fi first
#define se second
#define nl cout<<"\n"
#define TEST cout<<"TEST\n"
#define pr pair<lli,lli>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define vi vector<lli>
#define vpi vector<pr> 
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;
lli n,m;
void solve(){
    cin>>n>>m;
    vi res(n+1,0),a(n+1,0),ps(n+1,0);
    NA(i,0,n) cin>>a[i]; 
    sort(a.begin(),a.begin()+n);
    ps[0]=a[0];
    NA(i,1,n) ps[i]=ps[i-1]+a[i];
    NA(i,0,n){
        res[i] = ps[i];
        if((i-m) >= 0) res[i]+=res[i-m];
    }
    NA(i,0,n) cout<<res[i]<<" ";
    return;
}
int main(){
	fastIO;  
    lli q=1; //cin>>q;
	NA(i,1,q+1) solve();
    return 0;
}