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

/*
Prerequisites.
    -> kth smallest element in an array in O(n). 
    -> QuickSelect algo.
    -> median find in O(n).

Pseudocode.

1. create (val/wt) array.
2. find median(val/wt) in array.
procedure(median,W):
    3. cal. sum of wt's of (val/wt)>median.
    4. if(W1==W) return median.
        else if(W1>W) newMed = median((vla/wt) < median), return procedure(newMed,W-M);
        else newMed = median((val/wt)>median), return procedure(newMed,W);


This whill only ensure that average time of O(n).
For worstcase O(n) -> check median-of-medians Algo.
*/
#define vfi vector<pair<float,float> >
vfi res;
vfi knapsak(vector<pair<float,float> > a, float w){
    lli pvt = rand() % a.size();
    float pt = a[pvt].first;
    vfi a1,b; float w2=0;
    if(a.size()==1 && a[0].second>w) {
        res.pb(mp(a[0].first,w));
        return a1;
    }
    NA(i,0,a.size()){
        if(a[i].first>pt) 
            b.pb(a[i]), w2+=(a[i].second);
        else a1.pb(a[i]);
    }
    if(w2==w) return b;
    if(w2>w) return knapsak(b,w);
    else{
        // append b to res.
        NA(i,0,b.size()) res.pb(b[i]);
        return knapsak(a1,w-w2);
    }
}
int main(){
    fastIO; lli n,b; cin>>n;
    float W,c; cin>>W;
    vector<pair<float,float> > a(n);
    NA(i,0,n) {
        cin>>c>>b; //a[i].first /=a[i].second, cout<<a[i].first<<" ";
        c = (c/b);
            a[i].first  = c;
        a[i].second = b;
        } 
    NA(i,0,n) cout<<a[i].first<<" "<<a[i].second,nl;
    vfi r = knapsak(a,W);
    NA(i,0,r.size())
        cout<<r[i].first,nl,res.pb(r[i]);
    NA(i,0,res.size())
        cout<<res[i].first<<" "<<res[i].second,nl;
    // float a,b; cin>>a>>b; cout<<a<<" "<<b<<" "<<(a/b);
    // vector<pair<float,float> > d;
    
    // float c = a/b; nl,cout<<c;
    return 0;
}