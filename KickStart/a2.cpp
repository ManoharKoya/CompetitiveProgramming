#include<bits/stdc++.h>
#define lli unsigned long long int
#define MOD 1000000007
#define KING 1000000002
#define queen 1000002
#define fi first
#define se second
#define se second
#define nl cout<<'\n'
#define TEST cout<<"TEST",nl
#define pr pair<lli,lli>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define vi vector<lli>
#define vpi vector<pr> 
#define P pair<lli,pr>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;
int n,ans=0; string s;
void solve(lli t){
    lli l,r,len,odds=0;
    cin>>l>>r; len=r-l+1;
    l--;
    vector<lli> ct(26,0); 
    NA(i,l,r)
        ct[s[i]-'A']++;
    NA(i,0,26) if(ct[i]%2) odds++;
    if(len%2) {if(odds==1) ans++;}
    else if(odds==0) ans++; 
}
int main(){
    fastIO;
    lli t,q,r=1; 
    while(t--){
        cin>>n>>q; cin>>s;
        NA(i,0,q) solve(i+1);
        cout<<ans<<'\n';
    }
    return 0;
}