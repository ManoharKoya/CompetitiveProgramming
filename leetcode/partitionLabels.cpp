#include<bits/stdc++.h>
using namespace std;
vector<int> partitionLabels(string S) {
    vector<int> f(26,-1),l(26),res;
    vector<pair<int,int> > rg(26,{0,0});
    for(int i=0;i<S.length();i++){
        f[S[i]-'a']++;
        if(rg[S[i]-'a'].first==-1) rg[S[i]-'a'].first=i, rg[S[i]-'a'].second=S[i]-'a';
        l[S[i]-'a']=i;
    }
    sort(rg.begin(),rg.end());
    for(int i=0;i<rg.size();++i) cout<<rg[i].first<<' '<<f[rg[i].second]<<' '<<char(rg[i].second+'a')<<'\n';
    return res;
}
int main(){
    string s; cin>>s;
    vector<int> r = partitionLabels(s);
    // for(int i=0;i<r.size();i++) cout<<r[i]<<' ';
    return 0;
}