class Solution {
public:
    int findAns(int st,int end,vector<int> &cuts,int stickst,int stickend,map<pair<int,int>,int> &dp)
    {
        if(st>end)
        {
            return 0;
        }
        if(dp.find({st,end})!=dp.end())
        {
            return dp[{st,end}];
        }
        int ans=INT_MAX;
        for(int j=st;j<=end;j++)
        {
            int crcost=(stickend-stickst)+findAns(st,j-1,cuts,stickst,cuts[j],dp);
            crcost+=findAns(j+1,end,cuts,cuts[j],stickend,dp);
            ans=min(ans,crcost);
        }
        return dp[{st,end}]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        map<pair<int,int>,int> dp;
        return findAns(0,cuts.size()-1,cuts,0,n,dp);
    }
};