class Solution {
public:
    int findFib(int n,vector<int> &dp)
    {
        if(n==0)
        {
            return 0;
        }
        if(n==1)
        {
            return 1;
        }
        if(dp[n]!=-1)
            return dp[n];
        dp[n]=findFib(n-1,dp)+findFib(n-2,dp);
        return dp[n];
        
    }
    int fib(int n) {
        vector<int> dp(n+2,-1);
        return findFib(n,dp);
    }
};