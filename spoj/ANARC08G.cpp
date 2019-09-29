#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define KING 100000000
#define queen 1000009
#define nl cout<<"\n"
#define test cout<<"TEST\n"
#define pr pair<lli,lli>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define vi vector<lli>
#define vpi vector<pr> 
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;
void solve(){
    lli n,c,poor,x,rich,y,res=0; cin>>n;
    vi a(n+1,0); test;
    NA(i,1,n+1)
        NA(j,1,n+1)
            cin>>c,a[i]-=c,a[j]+=c;
    test;
    multiset<tuple<lli,lli> > S;
    NA(i,1,n+1)
        S.insert(make_tuple(a[i],i));
    while(!S.empty()){
        tie(poor, x) = *S.begin(); S.erase(S.begin());
        tie(rich, y) = *S.rbegin(); S.erase(prev(S.end()));
        lli amt = min(-poor,rich);
        cout<<x<<"->"<<y<<" "<<amt,nl;
        poor+=amt; rich-=amt;
        if(poor) S.insert(make_tuple(-poor,x));
        if(rich) S.insert(make_tuple(rich,y));
    }
    return;
}
int main(){
    fastIO;
    solve();
    return 0;
}