#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define KING 1000000000
#define queen 100002
#define fi first
#define se second
#define nl cout<<"\n"
#define TEST cout<<"TEST\n"
#define pr pair<lli,lli>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define vi vector<lli>
#define vpi vector<pr> 
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;
priority_queue<pr> p,q;
lli n,m,sz,a,b,chef,ramsi; vector<list<lli>> l;
void solve(){
    chef=0,ramsi=0; m=0;
    cin>>n; l.resize(n);
    NA(i,0,n){
        cin>>sz; m+=sz;
        NA(j,0,sz){
            cin>>a,l[i].pb(a);
            if(j==0) p.push({a,i}); else if(j==(sz-1)) q.push({a,i});
        } 
    } // scanned..
    cout<<p.top().fi<<" "<<q.top().fi,nl;
    // TEST; exit(0);
    while(m){
        //chef 
        a = p.top().fi, b = p.top().se; p.pop();
        chef+=a; cout<<a<<" ";
        l[b].pop_front(); 
        if(l[b].size()) p.push({l[b].front(),b});
        m--; 
        if(!m) break; cout<<chef<<" "; nl;
        // TEST; exit(0);
        //ramsi
        a = q.top().fi, b = q.top().se; q.pop();
        ramsi+=a; cout<<a<<" ";
        l[b].pop_back();
        if(l[b].size()) q.push({l[b].back(),b});
        m--;  cout<<ramsi<<" "; nl;
        if(m<3) TEST; exit(0);
    }
    cout<<chef<<" "<<ramsi;
    return;
}
int main(){
	fastIO; 
    lli q=1; //cin>>q;
	NA(i,1,q+1) solve();
    return 0;
}