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
/*
    farmer(0),wolf(1),duck(2),corn(3).
    leftbank <-----> rightBank.
            Boat(capacity=2).
    avoid:
        wd,dc-> at same point.
*/
vector<lli> lft,rt;
vector<lli>::iterator it2 = rt.begin();
lli ck = 0;
lli opnB(lli g,lli dir){
    if(dir==1){
        rt.push_back(g); ck++;
        vector<lli>::iterator it = lft.begin();
        while(it!=lft.end()) {
            if(*it==g) lft.erase(it);
            it++;
        }
    } else {
        lft.pb(g); 
        vector<lli>::iterator it = rt.begin();
        while(it!=rt.end()){
            if(*it==g) {rt.erase(it); ck--;}
            it++;
        }
    }
    return 0;
}
void dfs(){
        if(!lft.empty()){
            vector<lli>::iterator it = lft.begin();
            while(it!=lft.end()){
                opnB(*it,1);
            }
        }
    return;
}
int main(){
    fastIO; 
    lft.pb(1),lft.pb(2);lft.pb(3);
    dfs();
    return 0;
}