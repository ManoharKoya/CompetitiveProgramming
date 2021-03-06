/*Set of +ve int and a value -> find if val is sum of any valid subset of array given.*/
#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define KING 1000000000
#define queen 1000009
#define pr pair<lli,lli>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define vi vector<lli>
#define vpi vector<pr > 
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;
vector<vector<lli> > lookUp;  // memoisation approach.
bool findSum(lli a[],lli n,lli s){
    if(s==0) return true;
    else if(s<0 || n<0) return false;
    if(lookUp[n][s]==-1)
    {
    bool inc = findSum(a,n-1,s-a[n]);
    bool exc = findSum(a,n-1,s);
    lookUp[n][s] = inc||exc;
    }
    return lookUp[n][s];
}
void solve(){
    fastIO;
    lli n; cin>>n;
    lookUp.resize(queen);
    NA(i,0,1000){
        lookUp[i].resize(1000,-1);
    }
    lli a[n]; NA(i,0,n) cin>>a[i];
    lli s; cin>>s;
    cout<<findSum(a,n-1,s)<<endl;
}
int main(){
    fastIO; 
    solve();
    return 0;
}