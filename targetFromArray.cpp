#include<bits/stdc++.h>
#include<iterator>
#define lli long long int
#define MOD 1000000007
#define pb push_back
#define INF 10000000007
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;
lli dp[51][51];
lli totWays(lli n,lli t,lli a[]){
    
}
int main(){
    lli t,n; cin>>t>>n;
    lli a[n]; NA(i,0,n) cin>>a[i];
    cout<<totWays(n,t,a)<<endl;
    return 0;
}