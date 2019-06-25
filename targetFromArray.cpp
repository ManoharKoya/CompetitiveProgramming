#include<bits/stdc++.h>
#include<iterator>
#define lli long long int
#define MOD 1000000007
#define pb push_back
#define INF 10000000007
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;
vector<pair<lli,char>> lst;
void printLst(vector<pair<lli,char>> lst){
    for(auto it : lst){
        cout<<'('<<it.second<<')'<<it.first;
    }
    cout<<endl;
    return;
}
lli totWays(lli pos,lli t,lli a[],lli n){
    if(pos<0) 
        return 0;
    if(t==0) {
         printLst(lst);
        return 1;}
    // 3 options
    // +a[i] or -a[i] or skip
    lli Iways1=0,Iways2=0,Eways=0;
    Eways = totWays(pos-1,t,a,n);

    lst.push_back({a[pos],'+'});
    Iways1 = totWays(pos-1,t-a[pos],a,n);
    lst.pop_back();

    lst.push_back({a[pos],'-'});
    Iways2=totWays(pos-1,t+a[pos],a,n);
    lst.pop_back();

    return Eways+Iways1+Iways2;
}
int main(){
    lli t,n; cin>>t>>n;
    lli a[n]; NA(i,0,n) cin>>a[i];
    cout<<totWays(n,t,a,n)<<endl;
    return 0;
}