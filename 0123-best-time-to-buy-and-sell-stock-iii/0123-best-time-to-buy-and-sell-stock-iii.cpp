class Solution {
public:
    int findAns(int indx,vector<int> &p,int buyed,int trnx,vector<vector<vector<int>>> &dp)
    {
        if(trnx>=2)
        {
            return 0;
        }
        int ans=0;
        if(indx==p.size()-1)
        {
            if(buyed==1)
            {
                return p[indx];
            }
            else
            {
                return 0;
            }
        }
        if(dp[indx][buyed][trnx]!=-1)
        {
            return dp[indx][buyed][trnx];
        }
        if(buyed==1)
        {
            //proceed
            ans=max(ans,findAns(indx+1,p,buyed,trnx,dp));
            //sell 
            ans=max(ans,p[indx]+findAns(indx+1,p,0,trnx+1,dp));
        }
        else
        {
            //procced without buying
            ans=max(ans,findAns(indx+1,p,buyed,trnx,dp));
            //proceed with buying
            ans=max(ans,findAns(indx+1,p,1,trnx,dp)-p[indx]);
        }
        return dp[indx][buyed][trnx]=ans;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+3,vector<vector<int>>(3,vector<int>(3,-1)));
        return findAns(0,prices,0,0,dp);
    }
};