#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define pb push_back
#define pr pair<lli,lli>
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;
void solve(){
    lli n,tp,tot=0; 
    cin>>n;
    lli a[n]; NA(i,0,n) cin>>a[i];
    NA(i,0,n){
        tp=a[i];  cout<<tp<<" ";
        tot+=tp;
        NA(j,i+1,n){
            tp=tp|a[j];
            cout<<tp<<" ";
            tot+=tp;
        }
    }
    cout<<tot<<endl;
    return;
}
int main(){
    lli t; cin>>t;
    NA(i,0,t) solve();
}