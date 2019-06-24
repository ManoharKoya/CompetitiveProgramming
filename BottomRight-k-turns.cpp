#include<bits/stdc++.h>
#include<vector>
#include<iterator>
#define lli long long int
#define MOD 1000000007
#define pb push_back
#define INF 10000000007
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;
lli n,m;
bool isValid(lli i,lli j){
    return (i>=0 && i<n && j>=0 && j<m);
}

lli totWays(lli i,lli j,lli k,bool isCOl){
    // base and overflow conditions
    if(k==-1 || isValid(i,j)) return 0;
    if(k==0 && i==n-1 && j==m-1) return 1;
    // recursion
    if(isCOl==true){
        return totWays(i+1,j,k,isCOl)+totWays(i,j+1,k-1,!isCOl);
    } 
    return totWays(i+1,j,k-1,!isCOl)+totWays(i,j+1,k,isCOl);
}
lli totWays(lli i,lli j,lli k){
    return totWays(i+1,j,k,true)+totWays(i,j+1,k,false);
}

int main(){
    lli k; cin>>n>>m>>k;
    cout<<totWays(0,0,k)<<endl;
    return 0;
}