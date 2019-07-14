#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define pb push_back
#define pr pair<lli,lli>
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;
lli totWays(lli n){
    lli bup[n+1];
    lli ct=0;
    bup[0]=0; bup[1]=1; bup[2]=2;
    NA(i,3,n+1){
        bup[i]=0;
        bup[i]+=bup[i-1];
        bup[i]+=bup[i-2];
        if(ct==0){bup[i]+=bup[i-3]; ct=-1;}
    }
    return bup[n];
}
int main(){
    lli n; cin>>n;
    cout<<totWays(n)<<endl;
    return 0;
}