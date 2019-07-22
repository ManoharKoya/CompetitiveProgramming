#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define pb push_back
#define pr pair<lli,lli>
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;
lli smallestSumSquareMatrix(lli a[][5]; lli a,lli b){
    lli ans = MOD;
    if(a==5) return 0;
    if(b==-1 || b==5) return MOD;
    ans = min(ans,smallestSumSquareMatrix(a,a+1,b));
    ans = min(ans,smallestSumSquareMatrix(a,a+1,b-1));
    ans = min(ans,smallestSumSquareMatrix(a,a+1,b+1));
    return ans;
}
int main(){
    lli tp,m=MOD,n=5; lli a[n][n];
    NA(i,0,n){
        NA(j,0,n){
            cin>>a[i][j];
        }
    }
    NA(i,0,5) {
        tp = smallestSumSquareMatrix(a,i,0);
        m = min(m,tp);
    }
    return 0;
}