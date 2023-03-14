class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        vector<int> cnt(nums.size(),1);
        int ans=0;
        for(int i=1;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i] && dp[j]+1>dp[i])
                {
                    dp[i]=dp[j]+1;
                    cnt[i]=cnt[j];
                }
                else if(nums[j]<nums[i] && dp[j]+1==dp[i])
                {
                    cnt[i]+=cnt[j];
                }
            }
            if(dp[i]>dp[ans])
            {
                ans=i;
            }
        }
        int c=0;
        for(int i=0;i<nums.size();i++)
        {
            if(dp[ans]==dp[i])
            {
                c+=cnt[i];
            }
        }
        return c;
    }
};