#include<bits/stdc++.h>
#define lli long long int
#define NA(i,n) for(lli i=0;i<n;i++)
using namespace std;
lli*[2] mul(lli** a, lli** b){
    lli** c = new int[2][2];
    NA(i,2){
        NA(j,2){
            c[i][j]=a[i][i]*b[i][j]+a[i][j+1]*b[i+1][j];
        }
    }
    return c;
}
lli fubLog(lli n){
    lli res=0;
    lli m[2][2] = {{1,1},{1,0}};
    lli r[2][2] = mul(m,m);
    NA(i,2){
        NA(j,2){
            cout<<r[i][j]<<endl;
        }
    }
    lli r[2][2] = {{1,1},{1,1}};
    while(n>0)
    {
        if(n&1)
            r = mul(r,m);
        n=n>>1;
        m = mul(m,m);
    }
    res = m[0][0]+m[0][1];
     |1 1|^(n-1) in log(n)   
     |1 0|
    return res;
}
int main(){
    fubLog(1);
    return 0;
}