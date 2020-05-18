#include<bits/stdc++.h>
using namespace std;
int singleNumber(vector<int>& nums) {
    int l = nums.size(),res=0,p=1;
    vector<int> r(32,0);
    for(int i=0;i<l;++i){
        for(int j=0;j<32;j++){
            r[j]+=((nums[i]>>j)&1);
        }
    }
    for(int i=0;i<32;++i) r[i]%=3;
    for(int i=0;i<32;i++) {
        p=1<<i;
        if(r[i]) res+=(r[i]*p);
    }
    return res;
}
int singleNumber1(int A[], int n) {
    int count[32] = {0};
    int result = 0;
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < n; j++) {
            if ((A[j] >> i) & 1) {
                count[i]++;
            }
        }
        result |= ((count[i] % 3) << i);
    }
    return result;
}
int main(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<singleNumber(a);
    return 0;
}