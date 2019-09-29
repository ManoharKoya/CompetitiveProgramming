#include<bits/stdc++.h>
#include<unordered_set>
#define lli long long int
#define MOD 1000000007
#define KING 1000000000
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
unordered_set<string > stt;
bool check(string s){
    lli c=0;
    NA(i,0,s.length()){
        if(s[i]=='(') c++;
        else if(s[i]==')') --c;
        if(c<0) return false;
    }
    if(c==0) return true;
    return false;
}
void bfs(string s){
    queue<string> q; string st; bool flg;
    lli le=0; q.push(s);
    while(!q.empty()){
        st = q.front(); q.pop();
        if(flg && st.length()<=le) return;
        NA(i,0,s.length()){
        st = string(s,0,i)+string(s,i+1,s.length());
        if(check(st)) flg=true,le=st.length(),stt.insert(st);
        if(!flg) q.push(st);
        }
    }
    return;
}
int main(){
    string s; cin>>s;
    bfs(s);
    auto it = stt.begin();
    for(it=stt.begin();it!=stt.end();++it){
        cout<<*it,nl;
    }
    return 0;
}