#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define KING 1000000000
#define queen 1000009
#define nl cout<<endl
#define pr pair<lli,lli>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define vi vector<lli>
#define vpi vector<pr> 
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;
lli dp[300][300];
lli solve(lli n,lli m,lli pos,lli c[]){
    if(pos==m-1) return n==0;
    lli t = 0;
    if(!dp[n,pos])
        while(t*c[pos]<n) {
            dp[n][pos]+=solve(n-t*c[pos],m,pos+1,c);
            ++t;
        }
    return dp[n][pos];
}
int main(){
	fastIO; 
    lli n,m; cin>>n>>m; lli c[m];
    NA(i,0,m) cin>>c[i];
    NA(i,0,n+1) NA(j,0,m+1) dp[i][j]=0;
    cout<<solve(n,m,0,c);
    return 0;
}