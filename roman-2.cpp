#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define pb push_back
#define pr pair<lli,lli>
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;
string Roman(int number) 
{ 
    lli num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000}; 
    string sym[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    string r; 
    lli i=12;    
    while(number>0) 
    { 
      lli div = number/num[i]; 
      number = number%num[i]; 
      while(div--) 
      { 
        r.append(sym[i]);
      } 
      i--; 
    } 
    return r;
} 
lli charInt(char s){
    lli n = (s%65)+10;
    return n;
}
lli powe(lli a,lli b){
    lli res=1;
    NA(i,0,b){
        res*=a;
    }
    return res;
}
lli romDec(string r){
    lli d=0,a,b=0;
    // find base 
    lli sz = r.length();
    NA(i,0,sz) {
       lli a = (r[i]);
        if(a>=65 && (a%65)+10>b) {
            b = (a%65)+10;
        }   
    }
    b++; //base
    NA(i,0,sz){
        d+=charInt(r[sz-1-i])*powe(b,i);
    }
    return d;
}
void solve(){
    lli n; cin>>n;
    while(n>0 && n<4000){
            string roman = Roman(n);
            n = romDec(roman);
    }
    cout<<n<<endl;
    // NA(i,0,101) {
    //     romDec(Roman(i));
    //     cout<<endl;
    // }
    return;
}
int main(){
    solve();
    return 0;
}