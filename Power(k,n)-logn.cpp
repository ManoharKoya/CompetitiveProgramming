#include <bits/stdc++.h> 
#define lli long long int
using namespace std;

long long int power(long long int x,long long int y,long long int p) 
{ 
	long long int res = 1;	 
	x = x % p; 
	while (y > 0) 
	{ 
		if (y & 1) 
			res = (res*x) % p; 
		y = y>>1; 
		x = (x*x) % p; 
	} 
	return res; 
} 
void solve(){
     lli n; cin>>n;
     lli MAX = 1000000007;
     lli ans = (power(2,n-1,MAX)*10)%MAX;
     cout<<ans<<endl;
     return;  
}

int main() 
{ 
lli t; cin>>t; for(lli i=0;i<t;i++) solve();
return 0; 
} 
