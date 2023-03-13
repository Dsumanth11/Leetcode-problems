class Solution {
public:
    int findAns(int i1,int i2,string &w1,string &w2,int l1,int l2,vector<vector<int>> &dp)
    {
        if(i1==l1)
        {
            return l2-i2;
        }
        if(i2==l2)
        {
            return l1-i1;
        }
        if(dp[i1][i2]!=-1)
        {
            return dp[i1][i2];
        }
        int ans=INT_MAX;
        if(w1[i1]==w2[i2])
        {
            ans=min(ans,findAns(i1+1,i2+1,w1,w2,l1,l2,dp));
        }
        ans=min(ans,(1+findAns(i1,i2+1,w1,w2,l1,l2,dp)));
        ans=min(ans,(1+findAns(i1+1,i2,w1,w2,l1,l2,dp)));
        ans=min(ans,(1+findAns(i1+1,i2+1,w1,w2,l1,l2,dp)));
        return dp[i1][i2]=ans;
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1,vector<int>(word2.size(),-1));
        return findAns(0,0,word1,word2,word1.size(),word2.size(),dp);
    }
};