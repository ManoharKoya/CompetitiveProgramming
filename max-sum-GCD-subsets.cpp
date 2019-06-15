#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define pb push_back
#define NA(i,n) for(lli i=0;i<n;i++)
using namespace std;
lli gcd(lli a,lli b){
    if(a==0) return b;
    return gcd(b%a,a);
}
void solve(){
    lli n,Maxgcd=0,tp; cin>>n;
    lli ar[n]; set<lli, greater<lli>> a;
    NA(i,n) {cin>>ar[i]; a.insert(ar[i]);}
    n = a.size(); //cout<<n<<endl;
     lli Pgcd[n],Sgcd[n];
     Pgcd[0]=*a.begin();  Sgcd[n-1]=*a.rbegin(); 
     auto it=a.begin(); lli i=1; it++;
    while(i<n){
        Pgcd[i]=gcd(Pgcd[i-1],*it);
        i++; it++; 
    }
    i=n-2;
    it=a.end(); it--; it--; 
    while(i>-1){
        Sgcd[i]=gcd(Sgcd[i+1],*it);
        i--; it--; 
    }
    
    // for(lli i=1;i<n;i++) Pgcd[i]=gcd(Pgcd[i-1],*(a+i));
    // for(lli i=n-2;i>=0;i--) Sgcd[i]=gcd(Sgcd[i+1],*(a+i));
    it=a.begin();
    NA(i,n){
        if(i==0) tp=*a.begin()+Sgcd[1];
        else if(i==n-1) tp=*a.rbegin()+Pgcd[n-2];
        else tp=gcd(Pgcd[i-1],Sgcd[i+1])+*it;
        Maxgcd = max(Maxgcd,tp);
        it++;
    }
    cout<<Maxgcd<<endl;
    return;
}
int main(){
    lli t; cin>>t;
    NA(i,t) solve();
    return 0;
}