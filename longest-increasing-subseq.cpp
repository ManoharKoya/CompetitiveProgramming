#include<bits/stdc++.h>
#include<vector>
#include<iterator>
#define lli long long int
#define INT32_MIN  -10000000
#define MOD 1000000007
#define pb push_back
#define N 4
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;
// Memoisation approach
lli LIS(lli a[],lli i,lli n,lli prev){
   if(i==n) return 0;
   lli with,withOut;
   withOut = LIS(a,i+1,n,prev);
   if(a[i]>prev){
       with = 1+LIS(a,i+1,n,a[i]);
   }
   return max(with,withOut);
}
void solve(){
    lli n; cin>>n;
    lli a[n]; NA(i,0,n) cin>>a[i]; 
    cout<<LIS(a,0,n,INT32_MIN)<<endl;
    return;
}
int main(){
    lli t; cin>>t;
    NA(i,0,t) solve(); 
    return 0;
}