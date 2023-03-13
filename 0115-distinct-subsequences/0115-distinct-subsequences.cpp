class Solution {
public:
    int mod=1e9+7;
    int findAns(int i1,int i2,int l1,int l2,string &t,string &s,vector<vector<long long int>> &dp)
    {
        if(i2==l2)
        {
            return 1;
        }
        if(i1==l1)
        {
            return 0;
        }
        if(dp[i1][i2]!=-1)
        {
            return dp[i1][i2]%mod;
        }
        int ans=0;
        if(t[i1]==s[i2])
        {
            ans+=findAns(i1+1,i2+1,l1,l2,t,s,dp)%mod;
        }
        ans+=findAns(i1+1,i2,l1,l2,t,s,dp)%mod;
        return dp[i1][i2]=ans%mod;
    }
    int subsequenceCounting(string &t, string &s, int lt, int ls) {
        // Write your code here.
        vector<vector<long long int>> dp(t.size()+1,vector<long long int>(s.size()+1,-1));
        return findAns(0,0,lt,ls,t,s,dp)%mod;
    } 
    int numDistinct(string s, string t) {
        return subsequenceCounting(s,t,s.size(),t.size());
    }
};