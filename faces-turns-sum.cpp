#include<bits/stdc++.h>
#include<vector>
#include<iterator>
#define lli long long int
#define MOD 1000000007
#define pb push_back
#define INF 10000000007
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;
lli dp[51][51];
lli totWays(lli f,lli t,lli s){
    if(t==0 && s==0) return 1;
    if(t<0 || s<0 || f*t<s || t>s ) return 0;
    if(dp[t][s]==0)
    NA(i,1,f+1) dp[t][s]+=totWays(f,t-1,s-i); // imp
    return dp[t][s];
}
int main(){
    lli F,T,S; cin>>F>>T>>S;
    NA(i,0,T+1){ NA(j,0,S+1) dp[i][j]=0; }
    cout<<totWays(F,T,S)<<endl;
    return 0;
}