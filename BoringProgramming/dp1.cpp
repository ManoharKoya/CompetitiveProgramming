#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define KING 1000000000
#define queen 1000009
#define pr pair<lli,lli>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define vi vector<lli>
#define vpi vector<pr> 
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;

vector<int> a,dp;

int fun(int n){
    if(n==0) return 1;
    if(n<0) return 0;
    if(dp[n]!=-1) return dp[n];
    int res=0;
    for(int i:a) res+=fun(n-i);
    return dp[n]=res;
}
void solve(int sm){
    cout<<fun(sm);
    return;
}
int main(){
    int n,sm; cin>>n>>sm;
    a.resize(n); dp.resize(queen, -1);
    NA(i,0,n) cin>>a[i];
    solve(sm);
}