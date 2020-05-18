#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define KING 1000000002
#define queen 1000002
#define fi first
#define se second
#define se second
#define nl cout<<'\n'
#define TEST cout<<"TEST",nl
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


class ft{
public:
    lli n; vi a;
    void init(vi &v) {
        n = v.size();
        a.resize(n+1);
        NA(i,1,n+1) a[i] = v[i-1];
        lli i=0, j;
        while(i<n) {
            j = i + (i & -i);
            if(j<n+1) a[j] += a[i];
            ++i;
        }
    }
    lli preS(lli ind){ // [1,ind];
        lli res = 0;
        while(ind>0) res+=a[ind], ind -= (ind & -ind);
        return res;
    }
    lli rangeSum(lli i, lli j){ // [i,j];
        return preS(j) - preS(i-1);
    }
    lli add(lli ind, lli val){
        while(ind<n+1) a[ind] += val, ind += (ind & -ind);
    }
    lli update(lli ind, lli val){
        lli prev = rangeSum(ind,ind);
        add(ind, val-prev);
    }
};

void solve(){
    lli n,q; cin>>n;
    vi v(n); 
    NA(i,0,n) cin>>v[i];
    ft *F = new ft();
    F->init(v);
    cin>>q;
    while(q--){
        lli t,a,b;
        cin>>t>>a>>b;
        if(!t) cout<<F->rangeSum(a,b)<<'\n';
        else if(t==1) F->update(a,b);
        else F->add(a,b); 
    }
    return;
}
int main(){
    fastIO;
    lli t; cin>>t;
    NA(i,0,t) solve();
    return 0;
}