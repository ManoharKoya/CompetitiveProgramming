#include<bits/stdc++.h>
using namespace std;
#define nl cout<<'\n'
#define NA(i,s,n) for(int i=s;i<n;i++)
string lcs(string s, string p){
    string c = "";
    int n = s.length(), m = p.length();
    int mat[n+1][m+1] = {0};
    // NA(i,0,n) NA(j,0,m) cout<<mat[i][j]; 
    NA(i,0,n+1) mat[i][0]=0;
    NA(i,0,m+1) mat[0][i]=0;
    NA(i,1,n+1){
        NA(j,1,m+1){
            if(s[i-1]==p[j-1]) mat[i][j]=mat[i-1][j-1]+1;
            else {
                mat[i][j] = max(mat[i-1][j], max(mat[i][j-1], mat[i-1][j-1]));
            }
        }
    }
    // NA(i,1,n+1){
    //     NA(j,1,m+1){
    //         cout<<mat[i][j]<<' ';
    //     } nl;
    // }
    
    int i=n, j=m;
    // back tracking for lcs..
    while(!((i==1 || j==1) && s[i]==p[j])){
        if(s[i-1]==p[j-1]){ c+=s[i-1]; i--, j--; continue; }
        if(mat[i-1][j]==mat[i][j]) {i--; continue;}
        if(mat[i][j-1]==mat[i][j]) {j--; continue;} 
    }
    return c;
}
int main(){   
    string s, p; 
    cin>>s>>p;
    cout<<lcs(s,p);
    return 0;
}