#include<bits/stdc++.h>
#include<vector>
#include<iterator>
#define lli long long int
#define MOD 1000000007
#define pb push_back
#define NA(i,n) for(lli i=0;i<n;i++)
using namespace std;
void solve(){
    lli n,sum=0,tps=0,c=0,tp; cin>>n; 
    lli a[n]; NA(i,n) {cin>>a[i]; sum+=a[i];}
    lli k,x; cin>>k>>x;
    lli d[n]; 
    NA(i,n) d[i]=(a[i]^x)-a[i];
    sort(d,d+n);
    tp=n-1;
    while(tp>=k-1){
        tps=0;
        NA(i,k){
            tps+=d[tp]; tp--;
        }
        if(tps>0) sum+=tps;
        else {c=-1; break;}
    }
    if(c==-1){ cout<<sum<<endl; return; }
    tps=0;
    NA(i,k){
        if(i<=tp) {tps+=d[i]; continue;}
        tps-=d[i];
    }
    if(tps>0) sum+=tps;
    cout<<sum<<endl; return;
}
int main(){
    lli t; cin>>t;
    NA(i,t) solve();
    return 0;
}