#include<bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

int main(){
    fastIO;
    int n,ans=0; cin>>n;
    vector<vector<int> > d(10, vector<int> (10,0) );
    for(int i=1; i<=n; i++){
        int f,l,j=i;
        f = i%10;
        while(j>0) l=j%10, j/=10;
        d[f][l]++;
    }
    for(int i=0; i<=9; ++i){
        for(int j=0; j<=9; ++j){
            ans += (d[i][j] * d[j][i]);
        }
    }
    cout<<ans;
    return 0;
}