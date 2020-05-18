#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define KING 1000000000
#define queen 1000009
#define CLR(a) memset((a),0,sizepf(a))
#define pr pair<lli,lli>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define vi vector<lli>
#define vpi vector<pr> 
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;

struct dsu{
	lli par[200200],sz[200200];
	inline void init(lli _n){ NA(i,0,_n) par[i]=i,sz[i]=1;}
	inline lli find(lli now){
		if(par[now]==now) return now;
		return par[now]=find(par[now]);
	}
	inline bool uni(lli a, lli b){
		lli Pa(find(a)),Pb(find(b));
		if(Pa==Pb) return false;
        if(sz[Pa]<sz[Pb]) par[Pa]=par[Pb],sz[Pb]+=sz[Pa];
        else par[Pb]=par[Pa],sz[Pa]+=sz[Pb];
		return true;
	}
};


lli arr[queen],sz[queen];

void initialize(lli n){
    NA(i,0,n+1) {arr[i]=i; sz[i]=1;}  
    return;
}
lli root(lli i){
    while(i!=arr[i]){
        i=arr[i];
    }
    return i;
}
void weighted_union(lli a,lli b){
    lli ra,rb;
    ra=root(a); rb=root(b);
    if(sz[ra]<sz[rb]){
        arr[ra]=arr[rb]; 
        sz[rb]+=sz[ra];  return;
    } else {
        arr[rb]=arr[ra];
        sz[ra]+=sz[rb];  return;
    }
}
int main(){
    fastIO; 
    lli n,m,a,b; cin>>n>>m;
    initialize(n);
    NA(i,0,m){
        cin>>a>>b; weighted_union(a,b);
    }
    NA(i,1,n+1){
        cout<<arr[i]<<" ";
    }
    return 0;
}