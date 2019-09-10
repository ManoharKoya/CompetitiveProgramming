#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define KING 1000000000
#define queen 1000009
#define nl cout<<endl
#define pr pair<lli,lli>
#define pb push_back
#define eb emplace_back
// #define mp make_pair
#define vi vector<lli>
#define vpi vector<pr> 
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;

/*
    One day Polycarp published a funny picture in a social network making a poll about the color of his handle. Many of his friends started reposting Polycarp's joke to their news feed. Some of them reposted the reposts and so on.

These events are given as a sequence of strings "name1 reposted name2", where name1 is the name of the person who reposted the joke, and name2 is the name of the person from whose news feed the joke was reposted. It is guaranteed that for each string "name1 reposted name2" user "name1" didn't have the joke in his feed yet, and "name2" already had it in his feed by the moment of repost. Polycarp was registered as "Polycarp" and initially the joke was only in his feed.

Polycarp measures the popularity of the joke as the length of the largest repost chain. Print the popularity of Polycarp's joke.


*/

map<string,lli> dp;
map<string,vector<string> > mp;

void strcvt(string &s){
    NA(i,0,s.length()) if(s[i]<97) s[i]+=32;
    return;
}

void dfs(string s,string rt){
    lli mx = 0;
    dp[s]=1;
    NA(i,0,mp[s].size()){
        string tp = mp[s][i];
        if(tp==rt) continue;
        dfs(tp,s);
        mx = max(mx,dp[tp]);
    }
    dp[s]+=mx;
    return; 
}

void solve(){
    lli n; cin>>n;
    string s1,s2,st;
    NA(i,0,n){
        cin>>s1>>st>>s2;
        strcvt(s1),strcvt(s2);
        mp[s1].pb(s2); mp[s2].pb(s1);
    }
    dp["."]==0;
    dfs("polycarp",".");
    cout<<dp["polycarp"];
	return;
}
int main(){
	fastIO; solve();
    return 0;
}