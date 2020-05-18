#include<bits/stdc++.h>
using namespace std;

vector<int> Formlps(string b){
    vector<int> res(b.length());
    res[0]=0;
    int ct=0;
    for(int i=1;i<b.length();++i){
        if(b[i]==b[ct]) ct++;
        else ct=0; 
        res[i]=ct;
    }
    return res;
}
bool kmp(string a,string b){
    vector<int> lps = Formlps(b);
    int i=0,j=0;
    while(i<a.length()){
        if(a[i]==b[j]) i++,j++;
        else if(j==0) i++;
        else {
            j=lps[j-1];
        }
        if(j==b.length()) return true;
    }
    return false;
}
int main(){
    string a,b;
    cin>>a>>b;
    cout<<kmp(a,b);
    return 0;
}