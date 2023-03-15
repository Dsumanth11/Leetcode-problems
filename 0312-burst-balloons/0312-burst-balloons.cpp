class Solution {
public:
    int findAns(int st,int end,vector<int> &nums,vector<vector<int>> &dp)
    { 
        if(st>end)
        {
            return 0;
        }
        if(dp[st][end]!=-1)
        {
            return dp[st][end];
        }
        int ans=INT_MIN;
        for(int i=st;i<=end;i++)
        {
            ans=max(ans,(nums[st-1]*nums[end+1]*nums[i])+findAns(st,i-1,nums,dp)+findAns(i+1,end,nums,dp));
        }
        return dp[st][end]=ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size()+2,vector<int>(nums.size(),-1));
        return findAns(1,nums.size()-2,nums,dp);
    }
};