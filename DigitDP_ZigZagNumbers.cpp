#include <bits/stdc++.h>
#define lli long long int
#define NA(i,s,n) for(lli i=s; i<n; ++i)
#define mod 1000000007
using namespace std;
string s; lli n;

lli dp[1234][10][2][2];

lli fun(lli ind, lli prev, bool fg, bool fg1){
    if(ind==n) return 1;
    if(ind>n) return 0;
    if(prev!=-1 && dp[ind][prev][fg][fg1]!=-1) return dp[ind][prev][fg][fg1];
    lli ans = 0;
    if(fg){
        NA(i,0,10){
            lli cur = s[ind]-'0';
            if(i>cur) break;
            if(i==0 && i<=cur) {
                if(cur==i) ans = (ans + fun(ind+1, i, 1, fg1))%mod;
                else ans = (ans + fun(ind+1, i, 0, fg1))%mod;
            } // 0 less, 1 equal
            else {
                if((ind%2) ^ fg1) {
                    // pre > cur.
                    if(prev > i) {
                        if(cur==i) ans =  (ans + fun(ind+1, i, 1, fg1))%mod;
                        else ans =  (ans + fun(ind+1, i, 0, fg1))%mod;
                    }
                } else {
                    // prev < cur.
                    if(prev < i){
                        if(cur==i) ans = (ans + fun(ind+1, i, 1, fg1) ) % mod;
                        else ans = (ans + fun(ind+1, i, 0, fg1))%mod;
                    }
                }
            }
        } 
    } else {
        NA(i,0,10){
            if((ind%2) ^ fg1){
                if(prev > i) ans =  (ans + fun(ind+1, i, 0, fg1)) % mod;
            } else {
                if(prev < i) ans = (ans + fun(ind+1, i, 0, fg1))%mod;
            }
        }
    }
    if(prev!=-1) return dp[ind][prev][fg][fg1] = ans;
    else return ans;
}


int getHill(string N){
    s = N;  
    n = N.length();
    NA(i,0,1234)
        NA(j,0,10)
            NA(k,0,2) NA(l,0,2) dp[i][j][k][l]=-1;

    lli a1 = fun(0, 0, 1, 0), a2 = fun(0, 10, 1, 1);
    // cout<<a1<<' '<<a2<<'\n';
    lli ans = (a1 + a2)%mod;
    return (int)ans;
}
int main(){
    string N;
    cin>>N;
    int result;
    result = getHill(N);
    cout<<result;
    return 0;
}