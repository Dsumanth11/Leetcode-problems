class Solution {
public:
    bool isPalindrome(string &str)
    {
        int st=0;
        int end=str.size()-1;
        while(st<end)
        {
            if(str[st]!=str[end])
            {
                return false;
            }
            st++;
            end--;
        }
        return true;
    }
    int findAns(int indx,string &s,vector<int> &dp)
    {
        if(dp[indx]!=-1)
        {
            return dp[indx];
        }
        if(indx==s.size())
        {
            return 0;
        }
        else
        {
            string temp="";
            string back="";
            int ans=INT_MAX;
            for(int j=indx;j<s.size();j++)
            {
                temp+=s[j];
                if(isPalindrome(temp))
                {
                    ans=min(ans,1+findAns(j+1,s,dp));
                }
            }
            return dp[indx]=ans;
        }
    }
    int minCut(string s) {
        vector<int> dp(s.size()+3,-1);
        return findAns(0,s,dp)-1;
    }
};