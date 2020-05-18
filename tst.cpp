#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define KING 1000000001
#define queen 100002
#define nl cout<<"\n"
#define pr pair<lli,lli>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define vi vector<lli>
#define vpi vector<pr> 
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;
lli res=0,n,s=0,ss=0;
vi a,ct;
void solve(){
    cin>>n; a.resize(n),ct.resize(n); if(n<2) {cout<<0; return;}
    NA(i,0,n) cin>>a[i],s+=a[i];
    if(s%3) {cout<<0; return;}
    s/=3;
    NA(i,0,n) {
        ss+=a[n-i-1]; 
        if(ss==s) ct[n-i-1]=1;
        else ct[n-i-1]=0;
    }
    NA(i,1,n)
        ct[n-i-1]+=ct[n-i];   
    ss=0;
    NA(i,0,n){
        ss+=a[i];
        if(ss==s && i+2<n-1)
            res+=ct[i+2];
    }
    cout<<res;
    return;
}
int main(){
    fastIO;
    solve(); 
    return 0;
}