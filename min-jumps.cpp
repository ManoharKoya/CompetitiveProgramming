#include<bits/stdc++.h>
#include<vector>
#include<iterator>
#define lli long long int
#define MOD 1000000007
#define pb push_back
#define INF 10000000007
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;
// a[0] as source 
// a[n-1] as destination
// Memoisation approach
lli minJumps(lli a[],lli i, lli n, lli lookback[]){
    lli min_jumps=INF,cost;
    if(i==n-1) return 0; // base case -> destination
    if(lookback[i]!=0) return lookback[i];
    if(a[i]==0 || i>=n) return INF;
    for(lli j=1;j<=a[i];j++){
        cost = minJumps(a,i+j,n,lookback);
        if(cost!=INF) min_jumps = min(min_jumps,cost+1);
    }
    lookback[i]=min_jumps;
    return min_jumps;
}
void solve(){
    // enter array
    lli n; cin>>n;
    lli a[n]; NA(i,0,n) cin>>a[i];
    lli lookBack[n];
    NA(i,0,n) lookBack[i]=0;
    cout<<minJumps(a,0,n,lookBack)<<endl;
    // NA(i,0,n) cout<<lookBack[i]<<" ";
    return;
}
int main(){
    lli t; cin>>t;
    NA(i,0,t) solve(); 
    return 0;
}