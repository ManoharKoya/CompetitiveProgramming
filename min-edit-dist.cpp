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
int med(string a,string b){
    lli ad,dl,rp;
    lli n=a.length(),m=b.length();
    lli dp[n+1][m+1];
    NA(i,0,n+1) dp[i][0]=i;
    NA(i,0,m+1) dp[0][i]=i;
    NA(i,1,n+1){
        NA(j,1,m+1){
            ad=dp[i-1][j]+1; dl=dp[i][j-1]+1; rp=dp[i-1][j-1]+(a[i-1]==b[j-1] ? 0 : 1);
            dp[i][j]=min(ad,min(dl,rp));
        }
    } 
    cout<<dp[n][m]<<endl;
    return dp[n][m];
}
int main(){
    string a,b; 
    NA(i,0,3)
    {cin>>a>>b;
    med(a,b);}
}