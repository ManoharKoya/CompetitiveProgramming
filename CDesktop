#include<bits/stdc++.h>
#define lli long long int
#define NA(i,s,n) for(lli i=s; i<n; ++i)
#define nl cout<<'\n'
using namespace std;

lli n, k, c = 0, d = 0, m;
int main(){

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    cin>>n>>m;
    lli a[n]; NA(i,0,n) cin>>a[i], d+=a[i];
    double f = d / (4.0 * m); // cout<<f<<'\n';
    NA(i,0,n){
        if(a[i]>=f) c++;
    }
    if(c>=m) cout<<"Yes";
    else cout<<"No";
    return 0;
}