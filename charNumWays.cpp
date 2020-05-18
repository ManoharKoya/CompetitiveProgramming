#include<bits/stdc++.h>
using namespace std;
int numWays(string s, int pos){
    if(pos>=s.length()) return 0;
    else if(pos==s.length()-1) return 1;
    else if(s[pos]=='0') return 0;
    int res=0;
    res += numWays(s,pos+1);
    if(s[pos]<'3' && s[pos]<'7') res+=numWays(s,pos+2);
    return res;
} 
void solve(){
    string s; cin>>s;
    int res = numWays(s,0);
    cout<<res;
    return;
}
int main(){
    solve();
    return 0;
}