class Solution {
public:
    bool findAns(int i1,int i2,string &s1,string &s2,vector<vector<int>> &dp)
    {
        if(i1==s1.size() && i2==s2.size())
        {
            return true;
        }
        if(i2==s2.size())
        {
            return false;
        }
        if(i1==s1.size())
        {
            bool ans=true;
            while(i2<s2.size())
            {
                if(s2[i2]!='*')
                {
                    ans=false;
                }
                i2++;
                if(!ans)
                    return ans;
            }
            return ans;
        }
        if(dp[i1][i2]!=-1)
        {
            return dp[i1][i2]==1;
        }
        bool ans=false;
        if(s2[i2]=='?')
        {
            ans=ans|findAns(i1+1,i2+1,s1,s2,dp);
        }
        else if(s2[i2]=='*')
        {
            for(int move=0;move<=s1.size();move++)
            {
                // cout<<i1<<" "<<i2<<" "<<move<<"\n";
                // cout<<move+i1<<" "<<s1.size()<<"\n";
                if((move+i1)>s1.size())
                {
                    break;
                }
                ans=ans|findAns(i1+move,i2+1,s1,s2,dp);
                // cout<<i1<<" "<<i2<<" "<<move<<" "<<ans<<"\n";
                if(ans)
                {
                    dp[i1][i2]=ans;
                    return dp[i1][i2]==1;
                }
            }
        }
        else
        {
            if(s1[i1]==s2[i2])
            {
                dp[i1][i2]=findAns(i1+1,i2+1,s1,s2,dp);
                return dp[i1][i2]==1;
            }
            else
            {
                return (dp[i1][i2]=false)==1;
            }
        }
        return (dp[i1][i2]=ans)==1;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1,vector<int>(p.size()+1,-1));
        return findAns(0,0,s,p,dp);
    }
};