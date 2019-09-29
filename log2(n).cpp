#include<bits/stdc++.h>
#define lli unsigned long long int
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
// don't use bit shifting for 2^n upto 64 bits.
lli a[61],f[61];
void prec(){
    f[1]=0,f[2]=1; a[1]=0,a[2]=1;
    NA(i,3,60){
        f[i]=f[i-1]+f[i-2];
        a[i]=f[i]%10;
    }
    f[0]=f[59]+f[58];
    a[0] = f[0]%10;
    return;
}
lli logm(lli x){
    return 64 - __builtin_clzll(x) - 1;
}
lli power1(lli x,lli y) 
{ 
	lli res = 1;	 
	while (y > 0) 
	{ 
		if (y & 1) 
			res = (res*x); 
		y = y>>1; 
		x = (x*x); 
	} 
	return res; 
} 
void solve(){
	lli n,tp,i; cin>>n;
    i = logm(n); 
    tp  = power1(2,i);
    cout<<a[tp%60],nl;
	return;
}
int main(){
	fastIO; lli t; cin>>t;
    prec();
    NA(i,0,t) solve();
    return 0;
}