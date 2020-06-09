/********************************
*** ******** ********** *********
*** * ****** ********* * ********
*** ** ***** ******** *** *******
*** *** **** ******* ***** ******
*** **** *** ****** ******* *****
*** ***** ** ***** +++++++++ ****
*** ****** * **** *********** ***
*** *******  *** ************* **
*** ******** ** *************** *
**********_**********************
* |   /  / \  \     /    /\     *
* |  /  |   |  \   /    /  \    *
* | /   |   |   \ /    /    \   *
* |+\   |   |    |    /______\  *
* |  \  |   |    |   |        | *
* |   \  \_/     |   |        | *
********************************/
#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define KING 1000000002
#define queen 1000002
#define fi first
#define se second
#define se second
#define lsb(i) (i & -i)
#define Pi 3.141592653589793238
#define nl cout<<'\n'
#define TEST cout<<"TEST",nl
#define all(a) a.begin(), a.end()
#define remax(a, b) (a = ((a<b) ? b : a))
#define remin(a, b) (a = ((a<b) ? a : b))
#define pr pair<lli,lli>
#define pb push_back
#define eb emplace_back
#define precise(a) cout<<fixed<<setprecision(a)
#define mp make_pair
#define vi vector<lli>
#define vpi vector<pr> 
#define P pair<lli,pr>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;

lli power(lli x,lli y,lli p) { 
	lli res = 1;	 
	x = x % p; 
	while (y > 0) 
	{ 
		if (y & 1) 
			res = (res*x) % p; 
		y = y>>1; 
		x = (x*x) % p; 
	} 
	return res; 
} 


const lli N = 3e4 + 4;
lli bit[N] = {0}, n, q, c, d, e;


struct qr{ // update or getSum
    lli l, r, val, tp, ind; 
    qr(lli v, lli i) : val(v), tp(0), ind(i) {}
    qr(lli v, lli lft, lli rt, lli i) : val(v), l(lft), r(rt), ind(i), tp(1) {}
};

bool comp(qr &a, qr &b){
    if(a.val == b.val)
        return a.tp < b.tp;
    return a.val < b.val;
}

void add(lli pos, lli val){
    for(; pos<N; pos+=lsb(pos)) bit[pos] += val;
    return;
}

lli query(lli pos){
    lli res = 0;
    for(; pos>0; pos-=lsb(pos)) res += bit[pos];
    return res;
}
lli query(lli x, lli y){
    return query(y) - query(x-1);
}

void solve(){
    cin >> n;
    vector<qr> vq;
    NA(i,0,n){
        cin >> c;
        vq.pb(qr(c, i+1));
    }
    cin >> q;
    NA(i,0,q){
        cin >> c >> d >> e;
        vq.pb(qr(e, c, d, i));
    }
    sort(all(vq), comp);
    reverse(all(vq));
    lli sz = vq.size();    
    vi res(q);
    NA(i,0,sz){
        qr p = vq[i];
        if(p.tp == 0){
            add(p.ind, 1);
        } else {
            res[p.ind] = query(p.l, p.r);
        }
    }
    for(lli r:res) cout << r << '\n';
    return ;
}
int main(){
    fastIO;
    lli t = 1;
    // cin>>t;
    NA(i,0,t){
        solve();
    }
    return 0;

}
