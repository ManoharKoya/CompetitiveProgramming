#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define pb push_back
#define pr pair<lli,lli>
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;
void solve(){
    lli p,t,res=0,n=0; cin>>p;
    lli k = p*p; 
    lli i=0;
    while(1){
        i++;
        t = i*i; 
        if(res<t){
            if(res+t<k) {
                res+=t;
                n++; cout<<i<<" ";
            } else break;
        }
    }
    cout<<endl<<n+1<<endl;
    return;
}    
int main(){
    lli t; cin>>t;
    NA(i,0,t) solve();
    return 0;
}