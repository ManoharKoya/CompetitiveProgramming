#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define vi vector<lli>
#define pb push_back
#define NA(i,s,n) for(lli i=s; i<n; ++i)
#define INF 1e15

const lli N = 1e5 + 1;
lli a[N], n, q, b, c, d;


// data will store max_prefSum & max_suffSum & max_subSegSum & 
// and current_sum of a segment.

struct data{
    lli sum, pref, suff, res;
};

data make_data(lli val){
    data d;
    d.sum = val;
    d.pref = d.suff = d.res = val;
    return d;
}

data combine(data l, data r){
    data d;
    d.pref = max(l.pref, l.sum + r.pref);
    d.suff = max(r.suff, l.suff + r.sum);
    d.sum = l.sum + r.sum;
    d.res = max({r.res, l.res, l.suff + r.pref});
    return d;
}

data st[4*N];

void build(lli id, lli cur_l, lli cur_r){
    if(cur_l==cur_r) {
        st[id] = make_data(a[cur_l]);
    } else {
        lli mid = (cur_l + cur_r) >> 1;
        build(2*id, cur_l, mid);
        build(2*id+1, mid+1, cur_r);
        st[id] = combine(st[id*2], st[id*2 + 1]);
    }
    return;
}

void update(lli id, lli cur_l, lli cur_r, lli pos, lli val){
    if(cur_l==cur_r) {
        st[id] = make_data(val);
    } else {
        lli mid = (cur_l + cur_r) >> 1;
        if(pos <= mid) 
            update(id*2, cur_l, mid, pos, val);
        else 
            update(id*2 + 1, mid+1, cur_r, pos, val);
        st[id] = combine(st[id*2], st[id*2+1]);
    }
    return;
}

data query(lli id, lli cur_l, lli cur_r, lli l, lli r){
    if(l > r) return make_data(-INF);
    if(l==cur_l && r==cur_r) return st[id];
    lli mid = (cur_l + cur_r) >> 1;
    return combine( query(2*id, cur_l, mid, l, min(r, mid)), query(2*id + 1, mid+1, cur_r, max(mid+1, l), r) );
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    NA(i,0,n) cin >> a[i];
    build(1, 0, n-1);
    cin >> q;
    while(q--){
        cin >> b >> c >> d;
        if(!b){
            --c;
            update(1, 0, n-1, c, d);
        } else {
            --c, --d;
            cout << query(1, 0, n-1, c, d).res << '\n';
        }
    }
    return 0;
}
