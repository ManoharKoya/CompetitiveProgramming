// #include<bits/stdc++.h>
// using namespace std;
// #define NA(i,s,n) for(int i=s; i<n; ++i)
// int n; vector<int> a, dp;
// int fun(int ind){
//     if(ind>n-1) return 0; 
//     int with=-100, without;
//     if(ind==-1 || a[ind]<a[ind+1]) with = 1+fun(ind+1);
//     without = fun(ind+1);
//     return dp[ind+1]=max(with, without);
// }
// void solve(){
//     cin>>n;
//     a.resize(n), dp.resize(10001,-1);
//     NA(i,0,n) cin>>a[i];
//     fun(-1);
//     cout<<dp[0]<<' ';
//     return;
// }
// int main(){
//     solve();
//     return 0;
// }

#include<bits/stdc++.h>
#include<vector>
#include<iterator>
#define lli long long int
#define INT3_MIN  -10000000
#define MOD 1000000007
#define pb push_back
#define N 4
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;
// Memoisation approach
vector<lli> dp;
lli LIS(lli a[],lli i,lli n,lli prev){
   if(i==n) return 0;
   lli with,withOut;
   withOut = LIS(a,i+1,n,prev);
   if(a[i]>prev){
       with = 1+LIS(a,i+1,n,a[i]);
   }
   return dp[i]=max(with,withOut);
}
void solve(){
    lli n; cin>>n;
    dp.resize(10001, -1);
    lli a[n]; NA(i,0,n) cin>>a[i]; 
    LIS(a,0,n,INT3_MIN);
    cout<<dp[0]<<'\n';
    return;
}
int main(){
    lli t; cin>>t;
    NA(i,0,t) solve(); 
    return 0;
}