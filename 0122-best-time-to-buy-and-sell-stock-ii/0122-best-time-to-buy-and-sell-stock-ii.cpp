class Solution {
public:
    int findAns(int indx,vector<int> &prices,int buyed,vector<vector<int>> &dp)
    {
        if(indx==prices.size()-1)
        {
            if(buyed==1)
            {
                return prices[indx];
            }
            return 0;
        }
        if(dp[indx][buyed]!=-1)
        {
            return dp[indx][buyed];
        }
        if(buyed==0)
        {
            int notbuy=findAns(indx+1,prices,0,dp);
            int buy=findAns(indx+1,prices,1,dp)-prices[indx];
            return dp[indx][buyed]=max(buy,notbuy);
        }
        else
        {
            int sell=findAns(indx+1,prices,0,dp)+prices[indx];
            int notsell=findAns(indx+1,prices,1,dp);
            return dp[indx][buyed]=max(sell,notsell);
        }
        return 0;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1,vector<int>(3,-1));
        return findAns(0,prices,0,dp);
    }
};