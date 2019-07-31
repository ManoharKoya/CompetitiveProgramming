#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define KING 1000000000
#define max6 1000005
#define pr pair<lli,lli>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define vi vector<lli>
#define vpi vector<pr> 
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;
vi prime(max6,1);
vi primes;
void genPrime(){
    // prime array
    prime[0]=prime[1]=0;
    for(lli i=2;i*i<max6;i++){
        if(prime[i]){
            for(lli j=i*i;j<max6;j+=i) prime[j]=0;
        }
    }
    NA(i,0,max6) if(prime[i]) primes.pb(i); // primes in primes.
}
void solve(){
    vi cnt(max6,0);
    lli n,t; cin>>n;
    NA(i,0,n){
        cin>>t;
        for(lli j:primes){
            while(t%j==0){
                cnt[j]++; t/=j;
            }
        }
    }
    lli ans = 1;
    NA(i,0,max6){
        ans*=(cnt[i]+1);
    }
    cout<<ans<<endl;
    return;
}
int main(){
    fastIO; 
    genPrime();
    lli t; cin>>t;
    NA(i,0,t) solve();
    return 0;
}