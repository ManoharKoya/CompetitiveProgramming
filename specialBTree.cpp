#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define pr pair<lli,lli>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define vi vector<lli>
#define vpi vector<pr> 
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;
// lli nCrModPFermati(lli n, lli k,lli p)  
// {  
//     lli res = 1;  
//     if ( k > n - k )  
//         k = n - k;   
//     for (lli i = 0; i < k; ++i)  
//     {  
//         res *= (n - i); 
//         res /= (i + 1);  
//         res%=p;
//     }  
//     return res%p;  
// }  
lli f[1000001];
lli pow(lli a, lli b, lli ms)
{
 lli x=1,y=a; 
 while(b > 0)
 	{
 		if(b%2 == 1)
 	{
 		x=(x*y);
 		if(x>ms) x%=ms;
 	}
 	y = (y*y);
 	if(y>ms) y%=ms; 
 	b /= 2;
 	}
 return x;
}

lli InverseEuler(lli n, lli md)
{
 return pow(n,md-2,md);
}

lli nCrModPFermat(lli n, lli r, lli md)
{
 
 return (f[n]*((InverseEuler(f[r], md) * InverseEuler(f[n-r], md)) % md)) % md;
}

// lli power(lli x, lli y, lli p) 
// { 
//     lli res = 1;
//     x = x % p;  
//     while (y > 0) 
//     { 
//         if (y & 1) 
//             res = (res*x) % p; 
//         y = y>>1; 
//         x = (x*x) % p; 
//     } 
//     return res; 
// } 
// lli modInverse(lli n, lli p) 
// { 
//     return power(n, p-2, p); 
// } 
// lli nCrModPFermat(lli n, lli r, lli p) 
// { 
//    if (r==0 || n==0) 
//       return 1;
//     lli fac[n+1]; 
//     fac[0] = 1; 
//     for (lli i=1 ; i<=n; i++) 
//         fac[i] = fac[i-1]*i%p; 
  
//     return (fac[n]* modInverse(fac[r], p) % p * 
//             modInverse(fac[n-r], p) % p) % p; 
// } 
lli modFact(lli n, lli p) 
{ 
    if (n >= p) 
        return 0; 
    lli result = 1; 
   NA(i,1,n+1)
        result = (result * i) % p; 
    return result; 
} 
lli towPov(lli n){
    lli t =1; 
    while(1){
        t*=2; t--; 
        if(n<t) break;
        t++;
    }
    t++; t/=2; t--;
    return t;
}
void solve(){
    lli n,e,o; cin>>n;
    if(n%2) {
        e=n/2; o=(n/2)+1;
    } else {
        e=n/2; o=n/2;
    }
    lli t  = towPov(n); 
    lli e1,o1,e2,o2;
    e1 = e-((t-1)/2); o1=o-((t+1)/2);
    e2 = e-((t+1)/2); o2=o-((t-1)/2); 
    lli res = (modFact(e,MOD)*modFact(o,MOD))%MOD; 
    lli a = (nCrModPFermat((t+1)/2,e1,MOD)*nCrModPFermat((t+1)/2,o1,MOD)%MOD);
    lli b; if(n==t) b=0; else b = ((nCrModPFermat((t+1)/2,e2,MOD)*nCrModPFermat((t+1)/2,o2,MOD))%MOD);
    res = (res*((a+b)%MOD))%MOD;
    cout<<res<<endl;
    return ;
}
int main(){
    fastIO; 
    f[0] = 1;
	for(int i = 1 ; i <= 1000000 ; i++)
		f[i] = (f[i-1]*i)%MOD;
    lli t; cin>>t;
    NA(i,0,t) solve();
    return 0;
}