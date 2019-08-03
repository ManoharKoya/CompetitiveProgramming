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
lli strTolli(string s){
    lli res=0;
    for(lli i=0;i<s.length();i+=3){
        res = res*10 +((lli)(s[i])-48) * 10;
    }
    res/=10;
    return res;
}
void lliTostr(lli n){
    stack<lli> st;
    while(n>0){
        st.push(n%10); n/=10;
    }
    while(!st.empty()){
        cout<<st.top(); st.pop();
        if(!st.empty()) cout<<"->";
    }
}
void solve(){
    string s1,s2;
    cin>>s1>>s2; 
    lli n1 = strTolli(s1); lli n2 = strTolli(s2);
    lliTostr(n1+n2);
    return;
}
int main(){
    fastIO; 
    solve();
    return 0;
}