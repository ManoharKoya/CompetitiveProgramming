#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<queue>
#include<deque>
#include<stack>
#include<algorithm>
#include<map>
#include<iterator>
#define lli long long int
#define mp make_pair
#define gcd(a,b)  __gcd(a,b)
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0)
#define Pi  3.141592653589793
#define fo(i,n) for(lli i=0;i<(n);i++)
#define FO(i,x,n) for(lli i=(x);i<(n);i++)
#define FQ(i,x,n) for(lli i=(x);i<=(n);i++)
#define pf printf
#define pb push_back
#define sf scanf
#define vi vector<lli>
#define pi pair<lli,lli>
#define nl pf("\n")
using namespace std;
lli mod = 1e9 +7,test; 
lli max(lli a,lli b){return a>b?a:b;}
lli min(lli a,lli b){return a>b?b:a;}


vi BookScores;

bool cmp(lli i,lli j){
    return BookScores[i] > BookScores[j];
}
void solve(){
    lli b, l ,t,temp;
    cin>>b>>l>>t;
    vi bscore(b,0);
    fo(i,b){   cin>>bscore[i]; }
    vi signup(l,0);
    vi lnum(l,0) , lship(l,0);
    vector<pi > lsignup(l, make_pair(0,0));
    BookScores = bscore;
    vi lbooks[l];
    vector<pi > lvals(l,make_pair(0,0));
    fo(i,l){
            cin>>lnum[i] >> lsignup[i].first>>lship[i];
            lsignup[i].second = i;
            lvals[i].first = -1* (lsignup[i].first);
            lvals[i].second = i;
            fo(j,lnum[i]){
                cin>>temp;
                lbooks[i].push_back(temp);
                lvals[i].first += temp;
            }
            sort(lbooks[i].begin(),lbooks[i].end(),cmp);
        }
    sort(lvals.begin(),lvals.end());
    lli tTaken = 0;
    vi taken(b,0);
    vi libOrder;
    vi bookOrder[l];
    for(lli i=l-1;i>=0 && tTaken <= t;i--){
        lli clib = lvals[i].second;
        tTaken += lsignup[clib].first;
        lli curr = tTaken;
        lli last = 0;
        while (curr <= t){
            for(int d =0;d < lship[clib] && last < lnum[clib];d++){
                if(taken[lbooks[clib][last]]==0){
                taken[lbooks[clib][last]] = 1;
                bookOrder[clib].push_back(lbooks[clib][last++]);
                }else{
                    d--;
                    last++;
                }
            }
            curr++;
        }
        if(bookOrder[clib].size()!=0){
        libOrder.push_back(clib);
        }
    }
    cout<<libOrder.size()<<endl;
    for(lli lib : libOrder){
        if(bookOrder[lib].size()==0){
            continue;
        }
        cout<<lib<<" "<<bookOrder[lib].size()<<endl;
        for(lli book : bookOrder[lib]){
            cout<<book<<" ";
        }
        cout<<endl;
    }
}
int main(){
    lli t=1; 
    while(t--){
        solve();
    }
    return 0;
}