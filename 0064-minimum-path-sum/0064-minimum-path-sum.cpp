class Solution {
public:
    int findAns(int cr,int cc,vector<vector<int>>& grid,vector<vector<int>> &dp)
    {
        if(cr<0 || cc<0 || cr>=grid.size() || cc>=grid[0].size())
        {
            return 1e9;
        }
        if(cr==0 && cc==0)
        {
            return grid[cr][cc];
        }
        if(dp[cr][cc]!=-1)
        {
            return dp[cr][cc];
        }
        dp[cr][cc]=grid[cr][cc]+min(findAns(cr-1,cc,grid,dp),findAns(cr,cc-1,grid,dp));
        return dp[cr][cc];
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        return findAns(grid.size()-1,grid[0].size()-1,grid,dp);
    }
};