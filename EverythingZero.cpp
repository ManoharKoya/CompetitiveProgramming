#include<bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

/*

    Find the number of integers between 1 and N (inclusive) that contains exactly K non-zero digits when written in base ten.

                   -----------------------* DIGIT DP *--------------------------------
*/

string s; int k;
int dp[2][105][10];

int slv(int fg, int index, int nz){
    if(nz > k) return 0;
    if(index == s.length()){
        if(nz==k) return 1;
        else return 0;
    }
    if(dp[fg][index][nz]!=-1) return dp[fg][index][nz];
    int upto = 9;
    int res = 0;
    if(fg == 0) upto = s[index] - '0';
    for(int i=0; i<=upto; ++i){
        int nnz = (i!=0) ? nz+1 : nz, nindex = index+1;
        int nfg = (fg==0 && i==upto) ? 0 : 1;
        res += slv(nfg, nindex, nnz);
    }
    return dp[fg][index][nz] = res;
}

void solve(){
    memset(dp, -1, sizeof(dp));
    cin>>s>>k;
    cout<<slv(0,0,0);
    return;
}
int main(){
    fastIO;
    solve();
    return 0;
}