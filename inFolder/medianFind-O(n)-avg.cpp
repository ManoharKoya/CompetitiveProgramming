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
using namespace std::chrono;

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

ex output :
$ ./a
100000
16459
16000 ms <- O(N) avg case
16459
47114 ms <- O(NlogN)

*/

lli medianFind(vector<lli> a,lli k){
    if(a.size()==1 || k==0) return a[0];
    lli pvt = rand() % a.size();
    pvt = a[pvt];
    vi al,ar;
    NA(i,0,a.size()) (a[i]>=pvt) ? ar.pb(a[i]) : al.pb(a[i]);
    if(al.size()==k) return pvt;
    if(al.size()>k) return medianFind(al,k);
    else return medianFind(ar,k-al.size());  
}
int main(){
    lli n; cin>>n;
    vi a(n);
    NA(i,0,n) 
        a[i] = rand();
    auto start = high_resolution_clock::now();
    cout<<medianFind(a,n/2),nl;
    auto end = high_resolution_clock::now();
    auto dur = duration_cast<microseconds>(end-start);
    cout<<dur.count()<<" ms <- O(N) avg case",nl;

    start = high_resolution_clock::now();
    sort(a.begin(),a.end());
    cout<<a[n/2],nl;
    end = high_resolution_clock::now();
    dur = duration_cast<microseconds>(end-start);
    cout<<dur.count()<<" ms <- O(NlogN)",nl;

    return 0;
}