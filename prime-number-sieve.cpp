#include<bits/stdc++.h>
#include<vector>
#include<iterator>
#define lli long long int
#define MOD 1000000007
#define KING 100000000
#define nl cout<<"\n"
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
    lli s,e,a,b,c; cin>>s>>e;
    if(s!=1) s--;
    if(e!=(KING+1)) e++;
    bool tch[e-s+1];
    double E = e;
    double sqrtE = sqrt(E);
    // cout<<s<<endl;
    lli tp=s%2;
    NA(i,0,e-s+1) tch[i]=false;

    while(tp<e-s+1){
        tch[tp]=true; tp+=2; cout<<e+tp<<" ";
    }nl;
    NA(i,3,sqrtE){
        if(s%i==0) a=0; 
        else a=1;
        b=s/i; b+=a; b*=i; // cout<<"b "<<b<<endl;
        for(lli j=b;j<e+1;j+=(i)){
            tch[j-s]=true;
        }
    }
    
    NA(i,0,10){
        if(s+i==2 || s+i==3 || s+i==5 || s+i==7) { if(i>e-s) break; tch[i]=true;}
    }
    if(s==1) tch[0]=true;
    NA(i,0,e-s+1) if(!tch[i]) cout<<i+s<<" ";
    return;
}
int main(){
    lli t; cin>>t;
    NA(i,0,t) sieveStartEnd(); 
    return 0;
}