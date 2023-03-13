class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        vector<int> par1(nums.size(),0);
        vector<int> par2(nums.size(),0);
        for(int i=1;i<nums.size();i++)
        {
            par1[i]=i;
            par2[i]=i;
        }
        vector<int> dp1(nums.size(),1),dp2(nums.size(),1);
        for(int i=1;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j] && dp1[j]+1>dp1[i])
                {
                    dp1[i]=dp1[j]+1;
                }
            }
        }
        for(int i=nums.size()-2;i>=0;i--)
        {
            for(int j=nums.size()-1;j>i;j--)
            {
                if(nums[j]<nums[i] && dp2[j]+1>dp2[i])
                {
                    dp2[i]=dp2[j]+1;
                }
            }
        }
        int length_of_longest=0;
        for(int i=0;i<nums.size();i++)
        {
            if(dp1[i]==1 || dp2[i]==1)
            {
                continue;
            }
            else
            {
                length_of_longest=max(length_of_longest,dp1[i]+dp2[i]-1);
            }
        }
        // for(auto x:dp1)
        // {
        //     cout<<x<<" ";
        // }
        // cout<<"\n";
        // for(auto x:dp2)
        // {
        //     cout<<x<<" ";
        // }
        // cout<<"\n";
        return nums.size()-length_of_longest;
    }
};