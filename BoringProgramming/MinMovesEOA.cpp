/*
    Find the minimum number of moves to reach end of the array
    Given an array arr[] of size N where every element is from the range 
    [0, 9]. The task is to reach the last index of the array 
    starting from the first index. From ith index we
    can move to (i – 1)th, (i + 1)th or to any jth index where j ≠ i and arr[j] = arr[i].
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

vector<int> gp[1001];

void solve(){
    int n,a,b; cin>>n;
    NA(i,0,n) cin>>a>>b, ;    
    return;
}
int main(){
    fastIO;
    solve();
    return 0;
}
