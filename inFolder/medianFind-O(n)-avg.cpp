#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define KING 1000000000
#define queen 1000009
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

lli medianFind(vector<lli> a,lli k){
    if(a.size()==1 || k==0) return a[0];
    lli pvt = rand() % a.size();
    pvt = a[pvt];
    vi al,ar;
    NA(i,0,a.size()) (a[i]>=pvt) ? ar.pb(a[i]) : al.pb(a[i]);
    if(al.size()==k) return pvt;
    if(al.size()>k) return medianFind(al,k);
    else return medianFind(ar,k-al.size());  
}
int main(){
    lli n; cin>>n;
    vi a(n);
    NA(i,0,n) cin>>a[i];
    cout<<medianFind(a,n/2);
    return 0;
}