#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &a, int l, int h){
    int i=l,j=h;
    while(i<j){
    do{ i++; }while(a[i]<=a[l]);
    do{ j--; }while(a[j]<a[l]);
    if(i<j) swap(a[i], a[j]);
    }
    swap(a[j],a[l]);
    return j;
}
int quicksort(vector<int> &a, int l, int h){
    if(l<h){
        int j = partition(a,l,h);
        quicksort(a, l, j);
        quicksort(a, j+1, h);
    }
}
vector<int> solve(vector<int> &a){
    vector<int> res(a.size()+1);
    res[a.size()]=1e5+1;
    for(int i=0; i<a.size(); ++i) res[i]=a[i];
    quicksort(res, 0, res.size()-1);
    res.pop_back();
    for(int i=0; i<a.size(); ++i) cout<<res[i]<<' ';
    return res;
}
int main(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin>>a[i];
    solve(a);
    return 0;
}