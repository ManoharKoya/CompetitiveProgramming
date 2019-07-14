#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define pb push_back
#define pr pair<lli,lli>
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;
void solve(){
    lli n,t,s,tp,tp1,tp2; cin>>n>>t;
    lli p = t/2;
    lli r[n],jump[n];
    NA(i,0,n) r[i]=0;
    lli arr[n][p];
    NA(i,0,n){
        tp=0; tp2=0;
        NA(j,0,t){
            cin>>tp1; tp+=tp1; 
            if(j%2==1) {arr[i][tp2]=tp; tp2++;}
        }
        cin>>jump[i];
    }
    NA(i,0,p){
        tp=0; tp1=0;
        NA(j,0,n){
            if(jump[j]*arr[j][i]>tp) { tp=jump[j]*arr[j][i]; tp1=j;}
        }
        r[tp1]++;
    }
    // NA(i,0,n){
    //     NA(j,0,p){
    //         cout<<arr[i][j]<<" ";
    //     } cout<<endl;
    // }
    // NA(i,0,n){
    //     cout<<jump[i]<<" ";
    // } cout<<endl;
    tp=0; lli res;
    NA(i,0,n){
        if(tp<r[i]) {tp=r[i]; res=i;}
    }
    cout<<res+1<<endl;
    return;
}
int main(){
    solve();
    return 0;
}