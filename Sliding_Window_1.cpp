/*
    longest substring containing exactly k distinct characters.

    sliding_window_approach :
        move from left to right in main string.
        if considered substr have less no. of distinct chars -> extend substr to right.
        else if substr have more no. of diff chars -> decrement substr len by one from left.
        else extend right to unstable state to balence again (after higher no. of diff chars).
*/
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
    string s; cin>>s;
    lli curLen, mx=0, disLen, k, l, r; cin>>k;
    vector<lli> cnt(26,0);
    
    // disLen : no. of disticnt chars.
    // curLen : current string len.
    // mx : max str len with disLen == k.
    // l : left index , r : right index's of present current string.

    curLen = 1, disLen = 1, r=0, l=0;
    cnt[s[0]-'a']++;

    while(curLen>=1){
        if(disLen <= k) {
            // extend right.
            ++r, curLen++;
            if(r > s.length()-1) break;
            if(!cnt[s[r]-'a']) disLen++;
            cnt[s[r]-'a']++;
        } else if(disLen > k){
            // cut left.
            ++l, curLen--;
            cnt[s[l-1]-'a']--;
            if(!cnt[s[l-1]-'a']) disLen--;
        } 
        if(disLen==k) mx = max(mx, curLen);
    }

    cout<<mx<<'\n';
    return;
}  
int main(){
    fastIO;
    lli t; cin>>t; 
    while(t--) solve();
    return 0;
}
