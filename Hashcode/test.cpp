#include<bits/stdc++.h>
#define lli unsigned long long int
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

int b,l,d,remDays;
vector<int> s,t,m,order; // t-signup time, m-no.of books shipped per day.
vector<set<int> > lbs;
vector<bool> vis(1000001, 0), visInd(1000001, 0);
vector<int> BookOrder[100001];
// vector<pair<int,int > > libscr(100001, {0,0});

// bool Cmp(pair<int,int> p1, pair<int,int> p2 ){
//     return p1.first>p2.first;
// }

void scan(){
    cin>>b>>l>>d; remDays = d;
    s.resize(b); lbs.resize(l); t.resize(l), m.resize(l);
    NA(i,0,b) cin>>s[i];
    NA(i,0,l) {
        int n,tp;
        cin>>n>>t[i]>>m[i];
        NA(j,0,n) cin>>tp, lbs[i].insert(tp);
    }
    return;
}
pair<int, vector<int> >  score(int a){
    int res = 0;
    vector<pair<int,int>> scrs;
    vector<int> tpr;
    for(int i:lbs[a]) if(!vis[i]) scrs.pb({s[i],i}); 
    sort(scrs.begin(), scrs.end());
    reverse(scrs.begin(),scrs.end());
    int f = min(int(scrs.size()), (remDays-t[a])*m[a]);
    if(f<0) return {-1,tpr};
    NA(i,0,f) res+=scrs[i].first, tpr.pb(scrs[i].second);
    return {res, tpr};
}
int findFirst(){
    int scr = 0, ind = -1;
    vector<int> tpr; 
    NA(i,0,l) {
        if(visInd[i]) continue;
        pair<int,vector<int> > tp = score(i); 
        if(tp.first>scr) scr = tp.first, ind = i, tpr = tp.second;
    }
    //bookorder
    BookOrder[ind] = tpr;
    for(int i:tpr) vis[i]=1; 
    if(ind>-1) remDays -= m[ind];
    else remDays = -1;
    return ind;
}
void solve(){
    remDays = d; int indF=0;
    // int cnt = 0, last=0;
    while(remDays>0 || indF!=-1){
        indF = findFirst();
        // if(cnt==0) sort(libscr.begin(), libscr.end(), Cmp), last = 0;
        // else{
        //    indF =  
        // }
        // cnt++; cnt%=1000;
        if(indF<0) break;
        visInd[indF] = 1, order.pb(indF);
    }

    cout<<order.size()<<'\n';
    for(int i:order) {
        if(!BookOrder[i].size()) continue;
        cout<<i<<' '<<BookOrder[i].size()<<'\n';
        for(int j:BookOrder[i]) cout<<j<<' ';
        cout<<'\n';
    }
    return;
}
int main(){
    scan();
    solve();
    return 0;
}