#include<bits/stdc++.h>
#include<vector>
#include<iterator>
#define lli long long int
#define MOD 1000000007
#define pb push_back
#define NA(i,n) for(lli i=0;i<n;i++)
using namespace std;
void solve(){
    lli n,sum=0,tps=0,c=0,tp; cin>>n; 
    lli a[n]; NA(i,n) {cin>>a[i]; sum+=a[i];}
    lli k,x; cin>>k>>x;
    if(n<k) {cout<<sum<<endl; return;}
    lli d[n]; 
    NA(i,n) d[i]=(a[i]^x)-a[i];
    sort(d,d+n);
    lli pos=0,neg=0; tp=n-1;
    NA(i,n){
        cout<<d[i]<<" ";
        if(d[i]>0)pos++;
        else neg++;
    }
    cout<<endl<<pos<<" "<<neg<<endl;
    if(n>=k){
        if(pos<=k){
            NA(i,k){
                tps+=d[tp]; tp--;
            }
            if(tps>0) {sum+=tps; cout<<"hello"<<endl;}
        } else if(pos%k==0) {
            tp=n-1;
            NA(i,pos){
                tps+=d[tp]; tp--; 
            }
            cout<<tps<<endl;
            if(tps>0) {sum+=tps; cout<<"hi"<<endl;}
        } else {
            if((pos%k)%2==0){
                tp=n-1; 
                NA(i,pos){
                    tps+=d[tp]; tp--;
                }
                if(tps>0) {sum+=tps; cout<<"bunny"<<endl;}
                cout<<sum<<endl;
                return;
            }
            tp=n-1;
            NA(i,pos+1){
                tps+=d[tp]; tp--;
            }
            if(tps>0) {sum+=tps; cout<<"sunny"<<endl;}
            cout<<sum<<endl; return;
        }
     }
     cout<<sum<<endl; return;
}
int main(){
    lli t; cin>>t;
    NA(i,t) solve();
    return 0;
}