class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> par(nums.size(),0);
        sort(nums.begin(),nums.end());
        for(int i=0;i<par.size();i++)
        {
            par[i]=i;
        }
        vector<int> dp(nums.size(),1);
        for(int i=1;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0 && (dp[j]+1)>dp[i])
                {
                    dp[i]=dp[j]+1;
                    par[i]=j;
                }
            }
        }
        int max_ele=-1;
        int max_indx=-1;
        for(int i=0;i<dp.size();i++)
        {
            if(dp[i]>max_ele)
            {
                max_ele=dp[i];
                max_indx=i;
            }
        }
        vector<int> ans;
        while(par[max_indx]!=max_indx)
        {
            ans.push_back(nums[max_indx]);
            max_indx=par[max_indx];
        }
        ans.push_back(nums[max_indx]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};