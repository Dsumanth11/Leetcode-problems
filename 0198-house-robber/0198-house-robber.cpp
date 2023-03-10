class Solution {
public:
    int findAns(int indx,vector<int> &nums,vector<int> &dp)
    {
        if(indx<0)
            return 0;
        if(dp[indx]!=-1)
            return dp[indx];
        int take=nums[indx]+findAns(indx-2,nums,dp);
        int nottake=findAns(indx-1,nums,dp);
        dp[indx]=max(nottake,take);
        return dp[indx];
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return findAns(nums.size()-1,nums,dp);
    }
};