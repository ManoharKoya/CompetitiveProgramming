#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define pr pair<lli,lli>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define vi vector<lli>
#define vpi vector<pr> 
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;
vpi pairList;
void PreCompute(){
    lli x=0,y=0;
    while(x<=1e9){
        x=sqrt(y)+1;
        y+=x*x;
        pairList.pb(mp(x,y));
    }
    pairList.pop_back();
    return;
}    
void solve(){
    lli t; cin>>t;
    lli ct=0;
    NA(i,0,pairList.size()){
        if(pairList[i].first>t) break;
        else ct++;
    } 
    cout<<ct<<endl;
    return;
}
int main(){
    fastIO; 
    lli t; cin>>t;
    PreCompute();
    vpi::iterator it = pairList.begin();
    // lli sz = pairList.size(); cout<<sz<<endl;
    // NA(i,0,sz){
    //     cout<<pairList[i].first<<" "<<pairList[i].second<<endl;

    // }
    NA(i,0,t) solve();
    return 0;
}