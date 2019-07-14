#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define pb push_back
#define pr pair<lli,lli>
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;
float dist(lli x,lli y){
    return sqrt((y*y*1.0)+(x*x));
}
lli ncr(lli n, lli r) 
{ 
    lli p = 1, k = 1; 
    if (n-r<r) r=n-r; 
  
    if (r != 0) { 
        while (r) { 
            p *= n; 
            k *= r; 
           lli m = __gcd(p, k); 
            p /= m; 
            k /= m;
            n--; 
            r--; 
        }
    } 
    else
        p = 1; 
    return p;
} 
void solve(){
    lli n,x,y,v; cin>>n;
    lli ct,S=0;
    float dis;
    vector<pr> k;
    NA(i,0,n){
        cin>>x>>y>>v;
        dis = dist(x,y);
        lli tm = dis/v;
        ct=0;
        NA(i,0,k.size()){
            if(k[i].first==tm) {k[i].second++; ct=-1; break;}
        }
        if(ct==0) {k.push_back(make_pair(tm,1)); }
    }
    NA(i,0,k.size()){
        S+=ncr(k[i].second,2);
    }
    cout<<S<<endl;
    return;
}

int main(){
    solve();
    return 1;
}