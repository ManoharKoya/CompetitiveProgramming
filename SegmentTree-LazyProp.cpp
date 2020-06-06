#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define NA(i,s,n) for(lli i=s; i<n; ++i)
#define pb push_back
#define vi vector<lli>

const lli N = 1e5 + 1;
lli a[N], st[4*N], lazy[4*N], b, c, d, e, n;

void push(lli id, lli cur_l, lli cur_r){
    lli mid = (cur_l + cur_r) >> 1;
    lli a = (mid - cur_l + 1) * lazy[id], b = (cur_r - mid) * lazy[id];
    lazy[id*2] += a;
    lazy[id*2 + 1] += b;
    st[id*2] += a;
    st[id*2 + 1] += b;
    lazy[id] = 0;
    return;
}

void build(lli id, lli cur_l, lli cur_r){
    if(cur_l == cur_r) {
        st[id] = a[cur_l];
    } else {
        lli mid = (cur_l + cur_r) >> 1;
        build(id*2, cur_l, mid);
        build(id*2+1, mid+1, cur_r);
        st[id] = st[id*2] + st[id*2+1];
    }
    return;
}

void update(lli id, lli cur_l, lli cur_r, lli l, lli r, lli addOn){
    if(cur_l > cur_r || cur_l > r || cur_r < l) return;
    if(cur_l == l && cur_r == r){
        st[id] += (cur_r - cur_l + 1) * addOn;
        lazy[id] += addOn;
        return;
    } 
    push(id, cur_l, cur_r); // ....
    lli mid = (cur_r + cur_l) >> 1;
    update(id*2, cur_l, mid, l, min(r, mid), addOn);
    update(id*2 + 1, mid+1, cur_r, max(l, mid+1), r, addOn);
    st[id] = st[id*2] + st[id*2 + 1];
    return;
}

lli query(lli id, lli cur_l, lli cur_r, lli l, lli r){
    if(l > r || r < cur_l || l > cur_r) return 0LL;
    if(l <= cur_l && r >= cur_r) 
        return st[id];
    push(id, cur_l, cur_r);  // ....
    lli mid = (cur_l + cur_r) >> 1;
    return query(id*2, cur_l, mid, l, min(r,mid)) + query(id*2 + 1, mid+1, cur_r, max(l,mid+1), r);
}

int main(){

    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    lli n; cin >> n;
    NA(i,0,n) cin >> a[i];
    memset(lazy, 0LL, sizeof lazy);
    build(1, 0, n-1);    
    lli q; cin >> q;
    while(q--){
        cin >> b >> c >> d;
        if(b){ // update [c,d] addOn = e;
            cin >> e;
            update(1, 0, n-1, c, d, e);
        } else { // query_sum [c,d]
            cout << query(1, 0, n-1, c, d) << '\n';
        }
    }
    return 0;
}
