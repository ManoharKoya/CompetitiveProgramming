#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define KING 1000000000
#define queen 100002
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
bool lc(string a,string b){
	if(a<b) return 1;
	return 0;
}
void solve(){
	string s,r; lli tp;
	vi a(26,0);
	cin>>s>>r;
	NA(i,0,r.length()) a[r[i]-97]++;
	NA(i,0,s.length()){
		if(--a[s[i]-97]<0) {cout<<"Impossible",nl; return;}
	}
	bool fg = true;
	NA(i,0,26){
		if(fg) {
			if(i==(s[0]-97)){
				string ts1; NA(j,0,a[i]) ts1+=char(i+97);
				string ts2 = s+ts1; ts1+=s; 
				if(lc(ts2,ts1)) {cout<<s,fg=false; }
			}
			else if(i>(s[0]-97)) cout<<s,fg=false;
		}
		NA(j,0,a[i]) cout<<char(i+97);
	}
	if(fg) cout<<s;
	nl;
   	return;
}
int main(){
	fastIO; 
	lli t; cin>>t; NA(i,0,t) solve();
	// cout<<lc("bc","ba");
    return 0;
}