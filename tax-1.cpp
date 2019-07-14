#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define pb push_back
#define pr pair<lli,lli>
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;
vector<lli> readLine(){
    lli n;
    vector<lli> a;
    string line;
    getline(cin,line);
    istringstream iss(line);
    while(iss>>n){
        a.pb(n);
    }
    return a;
}
void solve(){
    lli neg,s=0;
    float tp;
    vector<lli> a,b,d,c;
    a = readLine();
    lli div = a.size();
    lli rg[div]; lli i=0;
    for(vector<lli>::iterator it=a.begin();it!=a.end();it++) {rg[i]=*it; i++;}
    b = readLine();
    float perc[div]; i=0;
    for(vector<lli>::iterator it=b.begin();it!=b.end();it++) {perc[i]=(float)((*it)/100); i++;}
    d = readLine();
    lli arr[d.size()]; i=0;
    for(vector<lli>::iterator it=d.begin();it!=d.end();it++) {arr[i]=(*it); i++;}
    c = readLine();
    lli n = c.size();
    lli tax[n]; i=0;
    for(vector<lli>::iterator it=c.begin();it!=c.end();it++) {tax[i]=*it; i++;}
    neg = arr[0];
    cout<<neg;
    NA(i,0,n){
        NA(j,0,div){
            tp = (float)(tax[i]/perc[j]);
            if(j==div-1 && tp>=rg[div-1]+1) {s+=tp; s+=neg; break;} 
            else if (tp>=rg[j]+1 && tp<=rg[j+1]) {s+=tp; s+=neg; break;}
        }
    }
    cout<<s<<endl;
    return;
}
int main(){
    solve();
    return 0;
}