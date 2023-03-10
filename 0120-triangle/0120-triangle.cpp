class Solution {
public:
    int findAns(int cr,int cc,vector<vector<int>>& t,vector<vector<int>> &dp)
    {
        if(cr==t.size())
        {
            return 0;
        }
        if(dp[cr][cc]!=-1)
            return dp[cr][cc];
        int down=findAns(cr+1,cc,t,dp);
        int dia=findAns(cr+1,cc+1,t,dp);
        dp[cr][cc]=t[cr][cc]+min(down,dia);
        return dp[cr][cc];
    }
    int minimumTotal(vector<vector<int>>& t) {
        int row=t.size();
        vector<vector<int>> dp(t.size(),vector<int>(t[row-1].size(),-1));
        dp[0][0]=findAns(0,0,t,dp);
        // for(int i=0;i<t.size();i++)
        // {
        //     for(int j=0;j<=i;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        return dp[0][0];
    }
};