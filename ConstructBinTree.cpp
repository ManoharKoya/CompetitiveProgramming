// #include <bits/stdc++.h>
// using namespace std;

// int main() {
// #ifdef _DEBUG
// 	freopen("input.txt", "r", stdin);
// //	freopen("output.txt", "w", stdout);
// #endif
	
// 	int t;
// 	cin >> t;
// 	while (t--) {
// 		int n, d;
// 		cin >> n >> d;
// 		int ld = 0, rd = n * (n - 1) / 2;
// 		for (int i = 1, cd = 0; i <= n; ++i) {
// 			if (!(i & (i - 1))) ++cd;
// 			ld += cd - 1;
// 		}
//         cout<<ld<<' '<<rd<<'\n';
// 		if (!(ld <= d && d <= rd)) {
// 			cout << "NO" << endl;
// 			continue;
// 		}
	
// 		vector<int> par(n);
// 		iota(par.begin(), par.end(), -1);
		
// 		vector<int> cnt(n, 1);
// 		cnt[n - 1] = 0;
		
// 		vector<int> bad(n);
		
// 		vector<int> dep(n);
// 		iota(dep.begin(), dep.end(), 0);
		
// 		int cur = n * (n - 1) / 2;
// 		while (cur > d) {
// 			int v = -1;
// 			for (int i = 0; i < n; ++i) {
// 				if (!bad[i] && cnt[i] == 0 && (v == -1 || dep[v] > dep[i])) {
// 					v = i;
// 				}
// 			}
// 			assert(v != -1);
// 			int p = -1;
// 			for (int i = 0; i < n; ++i) {
// 				if (cnt[i] < 2 && dep[i] < dep[v] - 1 && (p == -1 || dep[p] < dep[i])) {
// 					p = i;
// 				}
// 			}
// 			if (p == -1) {
// 				bad[v] = 1;
// 				continue;
// 			}
// 			assert(dep[v] - dep[p] == 2);
// 			--cnt[par[v]];
// 			--dep[v];
// 			++cnt[p];
// 			par[v] = p;
// 			--cur;
// 		}
	
// 		cout << "YES" << endl;
// 		for (int i = 1; i < n; ++i) cout << par[i] + 1 << " ";
// 		cout << endl;
// 	}
		
// 	return 0;
// }

#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define KING 1000000002
#define queen 1000002
#define fi first
#define se second
#define se second
#define nl cout<<'\n'
#define TEST cout<<"TEST",nl
#define pr pair<lli,lli>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define vi vector<lli>
#define vpi vector<pr> 
#define P pair<lli,pr>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;


void solve(){
    lli n,d,ld=0,rd=0,k; cin>>n>>d; 
    k = n; rd = n*(n-1) / 2;
    lli i=0; 
    while(k>0) {
        if(k > (1<<i)) {
            ld += ((1<<i) * i);
            k -= (1<<i);
        } else {
            ld += (k*i);
            k = 0;
        }
        ++i;
    }
    // cout<<ld<<' '<<rd<<' '<<d<<'\n';
    if( d < ld || rd < d) {cout<<"NO\n"; return;}

    vector<lli> par(n), cnt(n, 1), dep(n); 
    vector<bool> bad(n,0);
    cnt[n-1]=0; 
    iota(par.begin(), par.end(), -1);
    iota(dep.begin(), dep.end(), 0);

    lli cur = rd;

    while(cur>d){
        lli v = -1; // finding leaf at least depth.
        NA(i,0,n) {
            if(!bad[i] && cnt[i]==0 && (v==-1 || dep[i] < dep[v]))
                v = i;
        }
        if(v==-1) {
            cout<<"NO\n";
            return;
        }
        lli p = -1; // finding node at lev = dep[v]-2 and having vacancy in child. 
        NA(i,0,n){
            if(cnt[i]<2 && dep[i] < dep[v]-1 &&  (p==-1 || dep[i] > dep[p]))
                p = i;
        }
        if(p==-1) {bad[v]=1; continue;}
        ++cnt[p];
        --cnt[par[v]];
        par[v] = p;
        --dep[v];
        --cur;
        // cout<<cur<<'\n'; 
    }
    cout<<"YES\n";
    NA(i,1,n) cout<<par[i]+1<<' ';
    cout<<'\n';
    return;
}

int main(){
    fastIO;
    lli t=1; cin>>t;
    NA(i,0,t) solve();
    return 0;
}