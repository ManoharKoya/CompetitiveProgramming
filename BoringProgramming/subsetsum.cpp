#include<bits/stdc++.h>
using namespace std;
void SubsetSum(){
    int S,res=0,n; cin>>S>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    for(int i=0; i < (1<<n); i++){
        int tps = 0;
        for(int j=0; j<n; j++){
            if(i & (1<<j)) tps+=v[j];
        }
        if(tps==S) res+=1, cout<<"YES\n";
    }
    return;
}
int main(){
    SubsetSum();
    return 0;
}