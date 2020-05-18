#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define KING 1000000002
#define queen 1000002
#define fi first
#define se second
#define se second
#define lsb(i) (i & -i)
#define nl cout<<'\n'
#define TEST cout<<"TEST",nl
#define pr pair<lli,lli>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define vi vector<lli>
#define vpi vector<pr> 
#define P pair<lli,pr>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;

void solve(){
    lli d = 0;
    string s,res = ""; cin>>s;
    NA(j,0,s.size()){
        char i = s[j];
        lli curD = i - '0';
        while(curD > d) {
            ++d;
            res += '(';
        } 
        while(curD < d){
            --d; 
            res += ')';
        }
        res += i; 
    }
    while(d>0) {
        --d; 
        res += ')';
    }
    cout<<res<<'\n';
    return;
}
int main(){
    fastIO;
    lli t = 1; cin>>t; 
    NA(i,0,t) {
        cout<<"Case #"<<(i+1)<<": ";
        solve();
    }
    return 0;
}
