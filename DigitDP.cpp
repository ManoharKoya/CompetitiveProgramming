// How many numbers x are there in the range a to b, where the digit d occurs exactly k times in x? 
#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define KING 1000000000
#define queen 1000009
#define pr pair<lli,lli>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define vi vector<lli>
#define vpi vector<pr> 
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;

lli a,b,d,k;
vector<lli> num;
// vector<vector<vector<lli> > > DP; 
lli DP[12][12][2];

lli solve(lli pos,lli ct,lli f){
    if(ct>k) return 0;
    if(pos==num.size()){
        if(ct==k) return 1;
        return 0;
    }

    if(DP[pos][ct][f]!=-1) return DP[pos][ct][f];

    lli res=0,lt;
    if(f==0){ // prev all are equal to num.
        lt=num[pos];
    } else{ // something in prev is < num[i]. -> so we can go upto 9.
        lt=9;
    }
    // finding posiblities.
    NA(i,0,lt+1){
        lli tct = ct,tf=f;
        if(f==0 && i<lt) tf=1;
        if(i==d) tct++;
        if(tct<=k) res+=solve(pos+1,tct,tf);
    }
    return DP[pos][ct][f]=res;
}

lli ZtoP(lli p){
    num.clear();
    while(p>0) {num.pb(p%10); p/=10;}
    reverse(num.begin(),num.end());
    memset(DP,-1,sizeof(DP));
    return solve(0,0,0);
}
int main(){
    cin>>d>>k;
    cin>>a>>b;
    cout<<ZtoP(b)-ZtoP(a-1)<<endl;
    return 0;
}

