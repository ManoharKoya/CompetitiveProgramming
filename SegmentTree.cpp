#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back
#define vi vector<lli>
#define NA(i,s,n) for(lli i=s; i<n; ++i)

const lli N = 1e5 + 1;
lli a[N], st[4*N], n;

void build(lli id, lli l, lli r){
    if(l==r) {
        st[id] = a[l];
        return;
    } 
    lli mid = (l+r) >> 1;
    build(id*2, l, mid);
    build(id*2 + 1, mid + 1, r);
    st[id] = st[id*2] + st[id*2 + 1];
    return;
}

lli sum(lli id, lli cur_l, lli cur_r, lli l, lli r){
    // cur_l, cur_l --> current segment information. 
    // l, r --> query segment information.
    if(l > r) return 0;
    if(cur_l==l && cur_r==r) return st[id];    
    lli mid = (cur_l + cur_r) >> 1;
    return sum(2*id, cur_l, mid, l, min(r, mid)) + sum(2*id + 1, mid+1, cur_r, max(l, mid+1), r);
}

void update(lli id, lli cur_l, lli cur_r, lli pos, lli val){
    if(cur_l == cur_r) {
        st[id] = val; 
    } else {
        lli mid = (cur_l + cur_r) >> 1;
        if(pos <= mid) 
            update(id*2, cur_l, mid, pos, val);
        else 
            update(id*2 + 1, mid+1, cur_r, pos, val);
        st[id] = st[id*2] + st[id*2 + 1];
    }
    return;
}

int main(){
    cin >> n;
    NA(i,0,n) cin >> a[i];
    build(1, 0, n-1);
    cout << "DONE building\n";
    lli q, b, c, d; cin >> q;
    while(q--){
        cin >> b >> c >> d;
        if(b) { // add query.
            cout << sum(1, 0, n-1, c, d) << '\n';
        } else { // update query.
            update(1, 0, n-1, c, d);
        }
    }
    return 0;
}
