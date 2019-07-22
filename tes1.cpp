#include <iostream>
#include<bits/stdc++.h>
#define lli long long int
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;
lli n;
vector<vector<lli> > dp;
lli fun(lli s,lli k,lli a[]){
    if(s>n-1) return 0;
    if(k==1) return a[n-1]-a[s];
    if(dp[s][k]!=0) return dp[s][k];
    lli res = 1e9;
    NA(i,s,n){
        res = min(res, a[i]-a[s] + fun(i+1,k-1,a));
    }
    dp[s][k]=res;
    return res;
}
int main() {
    lli k; cin>>n>>k;
    dp.resize(n);
    NA(i,0,n){
        dp[i].resize(k,0);
    }
    NA(i,0,n){
        NA(j,0,k){
            dp[i][j]=0;
        }
    }
    lli a[n];
    NA(i,0,n) cin>>a[i];
    cout<<fun(0,k,a)<<endl;
return 0;
}