#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define KING 100000000
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

bool g[102][102];
lli n,m,K,A,B;
lli c[4] = {-1,0,1,0};
lli r[4] = {0,-1,0,1};

bool bfs(lli a,lli b,lli k){
    g[a][b] = false;
    NA(i,0,4){
        lli tc,tr;
        tc = a+c[i],tr = b+r[i];
        if(tc==A && tr==B && k-1<=0) return true;
        if(tc>0 && tr>0 && g[tc][tr]){
            if(bfs(tc,tr,k-1)) return true;
        }
    }
    g[a][b]=true;
    return false;
}   
void solve(){
    cin>>n>>m>>K;
    char ch; cin>>A>>B; 
    NA(i,1,n+1) NA(j,1,m+1) cin>>ch,(ch=='.') ? g[i][j]=true: g[i][j]=false;
    if(bfs(A,B,K)) cout<<"YES"; else cout<<"NO";
}
int main(){
    fastIO;
    solve();
    return 0;
}