#include<bits/stdc++.h>
#include<vector>
#include<iterator>
#define lli long long int
#define MOD 1000000007
#define pb push_back
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;
void solve(){
    lli n1,n2,n3; cin>>n1>>n2>>n3;
    lli a[n1+n2+n3];
    vector <lli> res;
    NA(i,0,n1+n2+n3) cin>>a[i];
    sort(a,a+n1+n2+n3);
    NA(i,0,n1+n2+n3-1){
        if(a[i]==a[i+1]){
            res.pb(a[i]);
            if(a[i]==a[i+2]) i+=2;
            else i++; 
        }
    }
    sort(res.begin(),res.end());
    for(auto it : res){
        cout<<it<<endl;
    }
    return;
}
int main(){
    lli t; cin>>t;
    NA(i,0,t) solve(); 
    return 0;
}