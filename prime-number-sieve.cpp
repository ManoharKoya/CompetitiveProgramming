#include<bits/stdc++.h>
#include<vector>
#include<iterator>
#define lli long long int
#define MOD 1000000007
#define pb push_back
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;
void sieveUptoN(){
    lli n; cin>>n;
    double N = n;
    bool touched[n+1];
    double sqrtN = sqrt(N);
    NA(i,0,n+1) touched[i]=false;
    lli tp=4;
    while(tp<n+1){
        touched[tp]=true; tp+=2;
    }
    NA(i,3,sqrtN){
        if(!touched[i]){
            for(lli j=i*i;j<n+1;j+=(2*i)){
                touched[j]=true;
            }
        }
    }
    NA(i,2,n+1){
        if(!touched[i]) cout<<i<<" ";
    }
    return;
}
void sieveStartEnd(){
    lli s,e; cin>>s>>e;
    bool tch[e-s+1];
    double E = e;
    double sqrtE = sqrt(E);
    lli tp=s%2;
    while(tp<e-s+1){
            tch[tp]=true; tp+=2;
    }
    NA(i,3,sqrtE){
        if(!s%i){}
    }
    // if(s==2 || s==1 || s==0) write it 
    return;
}
int main(){
    lli t; cin>>t;
    // double tt = t;
    // cout<<tt<<endl;
    NA(i,0,t) sieveUptoN();
    // NA(i,0,t) sieveStartEnd(); 
    return 0;
}