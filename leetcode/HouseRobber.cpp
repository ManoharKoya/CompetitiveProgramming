class Solution {
public:
    int dp[100001];
    int fun(vector<int> & nums, int s){
        if(dp[s]!=-1) return dp[s];
        dp[s] = max(fun(nums, s+1), nums[s]+fun(nums, s+2));
        return dp[s];
    }
    int rob(vector<int>& nums) {
        for(int i=0;i<nums.size();++i) dp[i]=-1;
        return fun(nums, 0);
    }
};
