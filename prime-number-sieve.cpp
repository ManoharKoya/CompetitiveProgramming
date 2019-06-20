#include<bits/stdc++.h>
#include<vector>
#include<iterator>
#define lli long long int
#define MOD 1000000007
#define pb push_back
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;
void sieveUptoN(){
    lli n,s; cin>>s>>n;
    double N = n;
    bool touched[n+1];
    double sqrtN = sqrt(N);
    NA(i,0,n+1) touched[i]=false;
    lli tp=4;
    while(tp<n+1){
        touched[tp]=true; tp+=2;
    }
    NA(i,3,N){
        if(!touched[i]){
            for(lli j=i*i;j<n+1;j+=(2*i)){
                touched[j]=true;
            }
        }
    }
    NA(i,s,n+1){
        if(!touched[i]) cout<<i<<" ";
    }
    return;
}
void sieveStartEnd(){
    return;
}
int main(){
    lli t; cin>>t;
    NA(i,0,t) sieveUptoN();
    // NA(i,0,t) sieveStartEnd(); 
    return 0;
}