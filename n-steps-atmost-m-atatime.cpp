#include<bits/stdc++.h>
#include<vector>
#include<iterator>
#define lli long long int
#define MOD 1000000007
#define pb push_back
#define NA(i,m,n) for(lli i=m;i<n;i++)
using namespace std;

lli totSteps(lli n,lli m, lli dp[]){
    if(n<0) return 0;
    if(n==0) return 1;
    if(dp[n]==0){
        NA(i,1,m+1){
            dp[n]+=totSteps(n-i,m,dp);
        }
    }
    return dp[n];
}
int main(){
    lli n,m; cin>>n>>m;
    lli dp[n+1];
    // NA(i,0,n+1) dp[n]=0;
    memset(dp,0,sizeof(lli)*(n+1));
    lli res=totSteps(n,m,dp);
    cout<<res;
    return 0;
}