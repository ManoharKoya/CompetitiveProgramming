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

int main(){
    fastIO;
    lli t,r=1; cin>>t;
    while(t--){
        lli res,sum=0,n,m; cin>>n;
        string s; cin>>s;
        if(n%2) m=(n+1)/2;
        else m = n/2;
        NA(i,0,m) sum+=(s[i]-'0');
        res = sum;
        for(lli i=0, j=m; j<n; ++i,++j) sum = sum + (s[j]-s[i]), (res<sum) ? res=sum : res=res;
        cout<<"Case #"<<r++<<": "<<res<<'\n';
    }
}