#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define pr pair<lli,lli>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define vi vector<lli>
#define vpi vector<pr> 
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;
void swap(lli &a,lli &b){
    lli c = a; a=b; b=c;
    return;
}
lli num_to_bits[16] = {0, 1, 1, 2, 1, 2, 2, 3,  
                    1, 2, 2, 3, 2, 3, 3, 4};  
 lli countSetBitsRec(lli num)  
{  
    lli nibble = 0;  
    if (0 == num)  
        return num_to_bits[0];  
    nibble = num & 0xf;  
    return num_to_bits[nibble] +  
            countSetBitsRec(num >> 4);  
}  
void solve(){
    fastIO;
    lli n,q,mx=0,tp=0; cin>>n>>q;
    lli a[n]; NA(i,0,n) cin>>a[i];
    lli sbts[n],xors[n];
    NA(i,0,n){
        tp=tp^a[i]; xors[n]=tp; sbts[i]=countSetBitsRec(tp); 
    }
    vector<vpi> sr;
    sr.resize(n); NA(i,0,n) sr[i].resize(n);
    NA(i,1,n){
        NA(j,i,n){
            sr[i][j].first=xors[j]^xors[i-1];
            sr[i][j].second=countSetBitsRec(xors[j]^xors[i-1]);
            if(sr[i][j].second%2==0) mx=max(mx,j-i);
        }
    }
    NA(i,1,n){
        NA(j,i,n) cout<<"("<<sr[i][j].first<<","<<sr[i][j].second<<") ";
        cout<<endl;
    }
    cout<<mx<<endl;
    return;
}
int main(){
    fastIO; 
    lli t; cin>>t;
    NA(i,0,t) solve();
    return 0;
}