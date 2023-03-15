class Solution {
public:
    int findAns(int st,int end,vector<int> &arr,int maxL,vector<int> &dp)
    {
        if(st>end)
        {
            return 0;
        }
        if(dp[st]!=-1)
        {
            return dp[st];
        }
        else
        {
            int ans=INT_MIN;
            for(int j=st;j<=min(end,st+maxL-1);j++)
            {
                int crans=(*max_element(arr.begin()+st,arr.begin()+j+1))*(j-st+1);
                crans+=findAns(j+1,end,arr,maxL,dp);
                ans=max(ans,crans);
            }
            return dp[st]=ans;
        }
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size()+5,-1);
        return findAns(0,arr.size()-1,arr,k,dp);
    }
};