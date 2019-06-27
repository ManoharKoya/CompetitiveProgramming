#include<bits/stdc++.h>
#include<vector>
#include<iterator>
#define lli long long int
#define MOD 1000000007
#define pb push_back
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;

void solve(){
    lli n,m; cin>>n>>m;
    lli c,d;
    lli c1=0,c2=0,d1=0,d2=0;
    NA(i,0,n){
        cin>>d>>c;
        if(c>c1 && d!=d1){
            c2=c1; d2=d1;
            c1=c; d1=d;
        }
        else if (c>c2 && c<c1 && d!=d1){
            c2=c; d2=d;
        }
    }
    cout<<c1+c2<<endl;
    return;
}
int main(){
    lli t; cin>>t;
    NA(i,0,t) solve(); 
    return 0;
}