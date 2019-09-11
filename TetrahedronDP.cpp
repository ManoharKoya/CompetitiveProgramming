#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define KING 1000000000
#define queen 1000009
#define nl cout<<endl
#define pr pair<lli,lli>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define vi vector<lli>
#define vpi vector<pr> 
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;
void solve(){
    lli steps; cin>>steps;
    lli a[2][steps+1]; 
    a[0][0] = 0,a[1][0]=1;
    NA(i,1,steps+1){
        a[0][i]=(a[1][i-1]+(2*a[0][i-1])%MOD)%MOD;
        a[1][i] = (3*a[0][i-1])%MOD;
    }
    cout<<a[1][steps]<<endl;
	return;
}
int main(){
	fastIO; solve();
    return 0;
}