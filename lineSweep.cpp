#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define KING 1e18
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
#define NA(i,s,n) for(lli i=s;i<n;++i)
using namespace std;
/*
    Algorithm to find the closest pair of points -> O(nlogn).
    idea :
        1. sort all points from left to right with x-coordinates.. 
        2. consider a vertical line from the initial point.
        3. initialize d = INF.
        4. move the present line from left to right on the sorted points.
        5. declar a set of points to hold points which are in the range of dist-d.
           i.e, which are in range([x-d,x],[y-d,y+d]).
        6. traverse over this set to check if any (dist  < d) => update d.
*/
vector<pair<double,double> > a; lli n,lft;
double d=KING;
bool cmp(pair<double,double> g,pair<double,double> h){
    return (g.se < h.se); 
}
void closestPr(){
    set<pair<double,double> > box;
    box.insert(a[0]); lft=0; 
    NA(i,1,n){
        while(lft<i && a[i].se-a[lft].se > d)   box.erase(a[lft++]); //erasing wrt x-coordinate.
        // earsing wrt y-cordinate..
        auto it = box.begin(); // cout<<it->first,nl;
        for(it=box.lower_bound(mp(a[i].first - d,a[i].second - d)); 
                it!=box.end() && (a[i].fi + d)>=(it->fi);
                    it++){
                d = min(d, sqrt(pow(a[i].fi - it->fi , 2)+pow(a[i].se - it->se, 2)));
        } 
        // insertion..
        box.insert(a[i]);
    }nl;
    cout<<d;
    return;
}
void solve(){
    cin>>n;
    a.resize(n);
    NA(i,0,n) cin>>a[i].se>>a[i].fi; // fi->y and se->x
    sort(a.begin(),a.end(),cmp);
    NA(i,0,n) cout<<"("<<a[i].se<<","<<a[i].fi<<")";
    closestPr();
    return;
}
int main(){
    fastIO; cout<<fixed<<setprecision(8);
    lli q=1; //cin>>q; 
    NA(i,0,q) solve();
    return 0;
}