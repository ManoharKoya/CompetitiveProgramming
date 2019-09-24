#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define KING 1000000000
#define queen 1000009
#define nl cout<<"\n"
#define pr pair<lli,lli>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define vi vector<lli>
#define vpi vector<pr> 
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;

vector<pr> points;
lli n; pr origin;
lli crossProd(pr a,pr b){
    return (a.first*b.second - a.second*b.first);
}
bool convex(pr a,pr b,pr c){
    pr v1 = mp(b.first-a.first,b.second-a.second);
    pr v2 = mp(c.first-b.first,c.second-b.second);
    return (crossProd(v1,v2)>0);
}
bool compAngle(pr &p1,pr &p2){
    if(convex(origin,p1,p2)) return true;
    if(convex(origin,p2,p1)) return false;
    // else colinear origin -> p1 -> p2.
    lli d1 = abs(p1.second-origin.second) + abs(p1.first-origin.first);
    lli d2 = abs(p2.second-origin.second) + abs(p2.first-origin.first);
    return (d1<d2);
}
vector<pr> convexHull(){
    vector<pr> res; 
    // find lowest and farest from origin.
    lli lst=0;
    NA(i,0,n) {
        if(mp(points[i].second,-points[i].first)<mp(points[lst].second,-points[lst].first))
            lst = i;
    }
    swap(points[0],points[lst]);

    //  sort points according to angles(if equal distances) from points[0].

    sort(points.begin()+1,points.end(),compAngle);  // check all driver functions

    NA(i,0,n) 
        cout<<"("<<points[i].first<<","<<points[i].second<<") ";
    nl;

    // store in vector if every alternative 3 forms convex or remove middle.
    res.pb(points[0]),res.pb(points[1]);
    lli pos = 2;
    while(pos<n){
        pr a = res[res.size()-1];
        pr b = res[res.size()-2];
        pr c = points[pos];
        if(!convex(a,b,c)){
            res.pop_back();
            if(pos<2){
                res.pb(c);
                ++pos;
            }
            continue;
        }
        res.pb(c); ++pos;
    }
    // if first and last 2 poinst are colinear or aren't forming convex remove middle.
    if(!convex(res[res.size()-2],res[res.size()-1],res[0])) res.pop_back();  
    return res;
}


int main(){
    fastIO; 
    cin>>n;  // vector<pair<lli,lli> > points;
    points.resize(n);
    NA(i,0,n) cin>>points[i].first>>points[i].second;
    vector<pair<lli,lli> > res = convexHull();
    NA(i,0,res.size()) cout<<"("<<res[i].first<<","<<res[i].second<<") ";
    return 0;
}