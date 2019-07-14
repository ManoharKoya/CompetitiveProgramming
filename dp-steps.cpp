/*
    Codu is trying to go down stairs from his building to ground floor.

He can go 3 ways:

1. Walk 1 step at a time.

2. Extend his legs and go 2 steps at a time.

3. Jump down 3 steps at a time.

Given n steps, calculate the number of possible ways to reach the ground floor, provided he can jump 3 steps at most once during this process.

That is, he can jump down 3 steps only once, but at any time, if he wishes, while walking down the stairs.
 */

#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define pb push_back
#define pr pair<lli,lli>
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;
lli ct=-1;
lli dpWays(lli n,lli dp[]){
    if(n<0) return 0;
    if(n==0) return 1;
    if(dp[n]==0){
        dp[n]+=dpWays(n-1,dp);
        dp[n]+=dpWays(n-2,dp);
        if(ct=-1) {dp[n]+=dpWays(n-3,dp); ct=0;}
    }
    return dp[n];
}
int main(){
    lli n; cin>>n;
    lli dp[n+1];
    memset(dp,0,sizeof(lli)*(n+1));
    cout<<dpWays(n,dp);
    return 0;
}