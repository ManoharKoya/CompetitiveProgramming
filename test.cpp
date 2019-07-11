#include<bits/stdc++.h>
#include<vector>
#include<iterator>
#define lli long long int
#define MOD 1000000007
#define pb push_back
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;

lli num_to_bits[16] = {0, 1, 1, 2, 1, 2, 2, 3,  
                    1, 2, 2, 3, 2, 3, 3, 4};  

lli countSetBitsRec(lli num)  
{  
    lli nibble = 0;  
    if (0 == num)  
        return num_to_bits[0];  
      
    // Find last nibble  
    nibble = num & 0xf;  
      
    // Use pre-stored values to find count  
    // in last nibble plus recursively add  
    // remaining nibbles.  
    return num_to_bits[nibble] +  
            countSetBitsRec(num >> 4);  
}  

  
void solve(){
    lli n,l=1;  cin>>n;
    cout<<countSetBitsRec(n)<<endl;
    NA(i,0,64) {
        l*=2;
    }
    cout<<l<<endl;
    return;
}
int main(){
    lli t; cin>>t;
    NA(i,0,t) solve(); 
    return 0;
}