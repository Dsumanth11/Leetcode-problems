class Solution {
public:
    int findAns(int cr,int cc,vector<vector<int>> &dp,vector<vector<int>> &obs)
    {
        if(cr<0 || cr>=dp.size() || cc<0 || cc>=dp[0].size())
            return 0;
        if(obs[cr][cc]==1)
        {
            return 0;
        }
        if(cr==0 && cc==0)
            return 1;
        if(dp[cr][cc]!=-1)
            return dp[cr][cc];
        dp[cr][cc]=findAns(cr-1,cc,dp,obs)+findAns(cr,cc-1,dp,obs);
        return dp[cr][cc];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows=obstacleGrid.size();
        int cols=obstacleGrid[0].size();
        vector<vector<int>> dp(rows,vector<int>(cols,-1));
        return findAns(rows-1,cols-1,dp,obstacleGrid);
    }
};