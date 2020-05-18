/*
    Given an array of 0s and 1s, If any particular index i has value 1 then it is a safe index 
    and if the value is 0 then it is an unsafe index. A man is standing at index -1(source) can 
    only land on a safe index and he has to reach the Nth index (last position). At each 
    jump, the man can only travel a distance equal to any Fibonacci Number. You have to 
    minimize the number of steps, provided man can jump only in forward direction.
*/
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
#define vpi vector<pr> 
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;

vector<int> fibs,dp;
vector<bool> a;
int n;

void prec(){
    fibs.resize(queen);
    fibs[0] = 0, fibs[1] = 1, fibs[2]=1;
    int i=3;
    while(i<queen){
        fibs[i] = fibs[i-1] + fibs[i-2];
        ++i;
    }
    return;
}

int fun(int ind){
    if(ind<-1 || ind>n) return MOD;
    // if(ind!=-1 && dp[ind]!=MOD) return dp[ind];  
    if(ind==n) return 0;
    int i=2,res=MOD;
    while(ind + fibs[i] <= n) {
        if(a[ind + fibs[i]] || ind+fibs[i]==n) cout<<ind+fibs[i]<<' ', res = min(res, 1+fun(ind+fibs[i]));
        ++i;
    }
    return res;
}

void solve(){
    prec();
    cin>>n;
    a.resize(n,0); dp.resize(queen, MOD);
    string s; cin>>s;
    NA(i,0,n) if(s[i]=='1') a[i]=1;
    // NA(i,0,n) cout<<fibs[i]<<' ';
    cout<<fun(-1);
    return;
}
int main(){
    fastIO;
    solve();
    return 0;
}