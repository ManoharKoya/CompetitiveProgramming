#include<bits/stdc++.h>
#include<unordered_map>
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
/*
    Counting no. that of rectangles can be formed by given list of points.
    O(N^2 * Log(N)) 
    Log(N)-for map. 
*/
void solve(){
    lli n,b,c,ans=0; cin>>n;
    set<pr> a; 
    map<pr,lli> m; // map for counting no.of vertical seg's of same top and bottom y-cord's
    NA(i,0,n) cin>>b>>c,a.insert({b,c});
    for(auto i: a){
        for(auto j:a){
            if(i.fi==j.fi && i.se>j.se){
                ans+=m[{i.se,j.se}]; // counting and adding rec's forming with y=i.se,j.se;
                m[{i.se,j.se}]++;
            }
        }
    }
    cout<<ans;
    return;
}
int main(){
	fastIO; lli q=1; //cin>>q;
	NA(i,0,q) solve();
    return 0;
}