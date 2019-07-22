#include<bits/stdc++.h>
#include<vector>
#include<iterator>
#define lli long long int
#define MOD 1000000007
#define pb push_back
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;

lli num_to_bits[16] = {0, 1, 1, 2, 1, 2, 2, 3,      /// g++ -std=c++11 -o a test.cpp 
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
    lli n,k,l,e,o; cin>>n;
    set<lli, greater<lli>> s;
    cin>>k; s.insert(k);
    if(countSetBitsRec(k)%2==0) cout<<1<<" "<<0<<endl;
    else cout<<0<<" "<<1<<endl;
    NA(i,1,n){
        cin>>k;
        const bool is_in = s.find(k) != s.end();
        if(is_in) {cout<<e<<" "<<o<<endl; continue;}
        vector<lli> s1;
        for(auto itr=s.begin();itr!=s.end();itr++){
            l = (*itr)^(k);
           if(l) s1.push_back(l);
        }
        for(auto itr=s1.begin();itr!=s1.end();itr++){
            s.insert(*itr);
        }
        s.insert(k);
        e=0; o=0;
        for (auto it=s.begin();it!=s.end();it++){
            if(countSetBitsRec(*it)%2==0) e++;
            else o++;
        }
        cout<<e<<" "<<o<<endl;
    }
    return;
}
int main(){
    lli t; cin>>t;
    NA(i,0,t) solve(); 
    return 0;
}