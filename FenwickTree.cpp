#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define KING 1000000000
#define queen 1000009
#define pr pair<lli,lli>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define vi vector<lli>
#define vpi vector<pr> 
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;

lli lsb(lli i) {return (i)&(-i);}

lli prefixSum(lli l,lli ft[]){
    lli s = 0;
    while(l>0){
        s+=ft[l];
        l &= ~lsb(l);
    }
    return s;
}

void solve(){
    // input array.
    lli n,t; cin>>n; lli a[n+1];
    NA(i,1,n+1) cin>>a[i];
    // construct tree.
    lli ft[n+1];  memcpy(ft,a,sizeof(a));
    NA(i,1,n+1){
        t = i+lsb(i);
        if(t<=n) ft[t]+=ft[i];
    }
    // point updates.
    lli q,d; cin>>q;
    NA(i,0,q) {
        cin>>t>>d;
        while(t<=n){
            ft[t]+=d;
            t+=lsb(t);
        }
    }
    // range query.
    lli l,r; cin>>l>>r;
    lli res = prefixSum(r,ft)-prefixSum(l-1,ft); 
    cout<<res<<endl;
    return;
}
int main(){
    fastIO;
    solve();
    return 0;
}

