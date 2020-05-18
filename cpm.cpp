#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define KING 1000000000
#define queen 100002
#define N 21
#define nl cout<<"\n"
#define TEST cout<<"testing",nl
#define pr pair<lli,lli>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define vi vector<lli>
#define vpi vector<pr> 
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;

// SAMPLE INPUT AND OUTPUTS 
/*
4 4
3 7 1 3
4 3
4 2
2 1
3 1
Enter no. of tasks and dependencies : Enter time req. for each task : Enter all (a,b) for which 'b' depends on 'a' :

OUTPUT:

FORMAT (i) -> earliest_st-ed latest_st-ed
1-> 0-3 0-3
2-> 3-10 3-10
3-> 3-4 9-10
4-> 10-13 10-13

critical taska are -> 1(A) 2(B) 4(D)
*/
/*
9 11
8 10 8 9 5 3 2 4 3
3 1 3 2
4 1
5 2
6 3 6 4
7 4
8 6 8 7
9 5 9 6
Enter no. of tasks and dependencies : Enter time req. for each task : Enter all (a,b) for which 'b' depends on 'a' :

OUTPUT:

FORMAT (i) -> earliest_st-ed latest_st-ed
1-> 0-8 1-9
2-> 0-10 0-10
3-> 10-18 10-18
4-> 8-17 9-18
5-> 10-15 17-22
6-> 18-21 18-21
7-> 17-19 19-21 
8-> 21-25 21-25
9-> 21-24 22-25

critical taska are -> 2(B) 3(C) 6(F) 8(H)
*/

lli n,m,a,b,mx=0; 

vi gp[N],gp1[N],es,ls,t; // gp is for EarliestSt(es), gp1 is for LatestSt(ls).
map<pr,vi> rm;
set<pr> ss; vpi vp;

lli dfs(lli nd,lli rt){
    es[nd] = max(es[nd],es[rt]+t[rt]);
    NA(i,0,gp[nd].size()){
        if(gp[nd][i]!=rt) dfs(gp[nd][i],nd);
    }
    return es[nd];
}
lli dfs1(lli nd,lli rt){
    if(rt==0) {
        if(es[nd]+t[nd]<mx) ls[nd] = mx-(es[nd]+t[nd])+es[nd];
        else ls[nd] = es[nd];
    } else {
        if(ls[nd]==-1) ls[nd]=es[nd]+(ls[rt]-(es[nd]+t[nd]));
        else ls[nd]=min(ls[nd],es[nd]+(ls[rt]-(es[nd]+t[nd])));
    }
    NA(i,0,gp1[nd].size()){
        if(gp1[nd][i]!=rt) dfs1(gp1[nd][i],nd);
    }
    return ls[nd];
}

void solve(){
    cout<<"Enter no. of tasks and dependencies : ";
    cin>>n>>m; 
    cout<<"Enter time req. for each task : ";
    es.resize(n+1,0),t.resize(n+1),ls.resize(n+1,-1);
    NA(i,1,n+1) cin>>t[i];
    cout<<"Enter all (a,b) for which 'b' depends on 'a' : \n";
    NA(i,0,m){
        cin>>a>>b;  // b is dependent on a.
        gp[b].pb(a); gp1[a].pb(b);
    }

    t[0]=0,es[0]=0;

    NA(i,1,n+1) 
        if(!gp1[i].size()) dfs(i,0);
    
    NA(i,1,n+1) mx = max(mx,es[i]+t[i]);

    NA(i,1,n+1) 
        if(!gp[i].size()) dfs1(i,0);
    nl,cout<<"FORMAT (i) -> earliest_st-ed latest_st-ed"; nl;
    NA(i,1,n+1) cout<<i<<"-> "<<es[i]<<"-"<<es[i]+t[i]<<" "<<ls[i]<<"-"<<ls[i]+t[i],nl;
    nl,cout<<"critical paths are -> ";
    // NA(i,1,n+1) if(!(ls[i]-es[i])) cout<<i<<"("<<char(64+i)<<") "; nl;
    // new 
    lli paths=1;
    NA(i,1,n+1)
        if(!(ls[i]-es[i])) rm[{ls[i],ls[i]+t[i]}].pb(i),ss.insert({ls[i],ls[i]+t[i]});
    auto it = ss.begin();
    while(it!=ss.end()){
        paths*=rm[*it].size();
        cout<<"(";
        NA(i,0,rm[*it].size()) { (i>0) ? cout<<"or " : cout<<""; cout<<char(64+rm[*it][i])<<" ";}
        cout<<")";
        it++;
    }
    nl,cout<<"No. of Criticalpaths are "<<paths;
    return;
}
int main(){
	fastIO; 
	solve();
    return 0;
}