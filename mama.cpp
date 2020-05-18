#include<bits/stdc++.h>
#define fi first
#define se second
#define NA(i,s,n) for(int i=s;i<n;++i)
#define pb push_back
using namespace std;
class item{
    public:
    string name; 
    double disocunt;
};
class shop{
    public:
    string name;
    int id;
    pair<int,int> pos;
    vector<item> itemList;
    map<string, double> itemMap;
};
class shopper{
    public:
    pair<int,int> pos;
    vector<item> itemList; // desires item list..
    map<string, double> itemMap;
    bool ignoreDist = false;
};
double distMan(pair<int,int> a, pair<int,int> b){
    return abs(a.fi-b.fi) + abs(a.se-b.se);
}
double distEuc(pair<int,int> a, pair<int,int> b){
    return sqrt((a.fi-b.fi)*(a.fi-b.fi) + (a.se-b.se)*(a.se-b.se));
}

vector<shop> shops;

shopper readShopper(){
    shopper spr;
    cin>>spr.pos.fi>>spr.pos.se;
    int in; cin>>in;
    spr.itemList.resize(in);
    NA(i,0,in) {
        cin>>spr.itemList[i].name;
        cin>>spr.itemList[i].disocunt;
        spr.itemMap[spr.itemList[i].name] = spr.itemList[i].disocunt;
    }
    cin>>spr.ignoreDist;
    return spr;
}
void readShops(){
    int n; cin>>n;
    shops.resize(n);
    NA(i,0,n) {
        shops[i].id = i;
        cin>>shops[i].name;
        cin>>shops[i].pos.fi>>shops[i].pos.se;
        int in; cin>>in;
        shops[i].itemList.resize(in);
        NA(j,0,in) {
            cin>>shops[i].itemList[j].name;
            cin>>shops[i].itemList[j].disocunt;
            shops[i].itemMap[shops[i].itemList[j].name] = shops[i].itemList[j].disocunt;
        }
    }
    return;
}
double costFun(shopper spr, shop sp){
    double cost = 0;
    NA(i,0,spr.itemList.size()){
        string nm = spr.itemList[i].name;
        double d = spr.itemList[i].disocunt;
        // diff between disc offered and disc required. -> should be more.
        cost += (sp.itemMap[nm] - d);
    }
    if(spr.ignoreDist){
        return (-cost);
    } 
    double d = distMan(spr.pos, sp.pos);
    return (-d)*(cost);
}
void solve(){
    shopper spr = readShopper();
    priority_queue<pair<double, int> > orderShops; // cost and shopIds.
    NA(i,0,shops.size()){
        // continue if shop not in same city.
        double pr = costFun(spr, shops[i]);
        orderShops.push({pr, shops[i].id});
    }
    while(!orderShops.empty()){
        cout<<orderShops.top().fi<<' ' <<orderShops.top().se<<' ';
        orderShops.pop();
    }
    return;
}

int main(){
    readShops();
    solve();
    return 0;
}