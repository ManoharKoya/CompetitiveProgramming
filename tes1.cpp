// How many numbers x are there in the range a to b, where the digit d occurs exactly k times in x? 
#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define KING 1000000000
#define queen 1000009
#define pr pair<lli,lli>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define vi vector<lli>
#define vpi vector<pr> 
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;

int main(){
    lli n,m,s,f; cin>>n>>m;
    lli a[n],b[n];
    NA(i,0,n) cin>>a[i];
    NA(i,0,n) cin>>b[i];
    priority_queue<pr> pq;
    NA(i,0,n){
        pq.push(mp(a[i]*b[i],i));
    }
    NA(i,0,m){
        s = pq.top().second;
        f = pq.top().first;
        pq.pop(); 
        pq.push(mp(f-b[s],s));
    }
    cout<<pq.top().first<<endl;
    return 0;
}

