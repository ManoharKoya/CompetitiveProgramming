/*
    Guddu was participating in a programming contest. He only had one problem left when his mother called him for dinner.
    Guddu is well aware how angry his mother could get if he was late for dinner and he did not want to sleep on an empty stomach,
     so he had to leave that last problem to you. Can you solve it on his behalf?
    For a given sequence of positive integers A1,A2,…,AN,
     you are supposed to find the number of triples (i,j,k) such that 1≤i<j≤k≤N and
    
    Ai⊕Ai+1⊕…⊕Aj−1=Aj⊕Aj+1⊕…⊕Ak,

    where ⊕ denotes bitwise XOR.
*/ 
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
void solve(){
    lli n,s=0,sz; cin>>n; 
    lli a[n+1],x[n+1]; a[0]=0; x[0]=0;
    NA(i,1,n+1) cin>>a[i];
    NA(i,1,n+1) x[i]=x[i-1]^a[i];
    map<lli, vector<lli> > p;
    NA(i,0,n+1){
        sz = p[x[i]].size(); 
        if(sz>0) {
            s += ((sz*(i-1))-p[x[i]][sz-1]);
            p[x[i]].pb(i+p[x[i]][sz-1]);
        }
        else p[x[i]].pb(i);
    }
    cout<<s<<endl;
    return;
}
int main(){
    fastIO; 
    lli t; cin>>t;
    NA(i,0,t) solve();
    return 0;
}