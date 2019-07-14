#include<bits/stdc++.h>
#include<vector>
#include<iterator>
#define lli long long int
#define MOD 1000000007
#define pb push_back
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;
/*
    Chef has K chocolates and he wants to distribute them to N people (numbered 1 through N). These people are standing in a line in such a way that for each i (1≤i≤N−1), person i and person i+1 are adjacent.

First, consider some way to distribute chocolates such that for each valid i, the number of chocolates the i-th person would receive from Chef is Ai and the sum S1=∑N−1i=1|Ai−Ai+1| is minimum possible. Of course, each person must receive a non-negative integer number of chocolates.

Then, Chef wants to create a new sequence B1,B2,…,BN by rearranging (permuting) the elements of the sequence A1,A2,…,AN. For each valid i, the number of chocolates the i-th person actually receives from Chef is Bi. Chef wants to distribute the chocolates (choose B1,B2,…,BN by permuting the sequence A and give Bi chocolates to the i-th person for each valid i) in such a way that S2=∑N−1i=1|Bi–Bi+1| is maximum possible. You need to find the maximum value of S2.

It is guaranteed that S2 does not depend on the exact choice of the sequence A1,A2,…,AN, as long as it is a sequence that minimises S1.
 */
lli mod(string num, lli a) 
{ 
    lli res = 0; 
      NA(i,0,num.length())
         res = (res*10 + (lli)num[i] - '0') %a; 
    return res; 
}
void solve(){
    lli n;
    string k; cin>>n; cin>>k;
    lli m = mod(k,n); if(m==0) {cout<<0<<endl; return;}
    lli l = n-m;
    cout<<(2*min(m,l))-1+((m==l)?0:1)<<endl;
    return;
}
int main(){
    lli t; cin>>t;
    NA(i,0,t) solve(); 
    return 0;
}