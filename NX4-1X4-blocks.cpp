#include<bits/stdc++.h>
#include<vector>
#include<iterator>
#define lli long long int
#define MOD 1000000007
#define pb push_back
#define INF 10000000007
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;

lli totWays(lli n){
    lli a[n+1];
    a[0]=0; a[1]=1; a[2]=1; a[3]=1; a[4]=2;
    NA(i,5,n+1){
        a[i]=a[i-1]+a[i-4];
    }
    return a[n];
}

int main(){
    lli n; cin>>n; 
    cout<<totWays(n)<<endl;
    return 0;
}