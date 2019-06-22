#include<bits/stdc++.h>
#include<vector>
#include<iterator>
#define lli long long int
#define MOD 1000000007
#define pb push_back
#define INF 10000000007
#define N 4
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;
// Memoisation approach
lli minCost(lli a[][N], lli i, lli lookback[]){
   if(lookback[i]!=0) return lookback[i];
   lli min_cost = a[0][i];
   NA(j,1,i){
       min_cost = min(min_cost,minCost(a,j,lookback)+a[j][i]);
   }
   lookback[i]=min_cost;
   return min_cost;
}
void solve(){
    // enter array
    lli d; 
    lli a[N][N]; 
    cin>>d;
    NA(i,0,N){
        NA(j,0,N){
            cin>>a[i][j];
        }
    }
    lli lookBack[N];
    NA(i,0,N) lookBack[i]=0;
    cout<<minCost(a,d,lookBack);
    // NA(i,0,n) cout<<lookBack[i]<<" ";
    return;
}
int main(){
    lli t; cin>>t;
    NA(i,0,t) solve(); 
    return 0;
}