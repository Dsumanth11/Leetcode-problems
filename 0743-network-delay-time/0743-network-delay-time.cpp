class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        map<int,vector<pair<int,int>>> mp;
        for(auto x:times)
        {
            mp[x[0]].push_back({x[1],x[2]});
        }
        vector<int> vis(n+1,0);
        vector<int> mt(n+1,INT_MAX);
        mt[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> qu;
        qu.push({0,k});
        while(!qu.empty())
        {
            auto x=qu.top();
            qu.pop();
            int ndval=x.second;
            int tm=x.first;
            if(vis[ndval]==1)
            {
                continue;
            }
            vis[ndval]=1;
            mt[ndval]=tm;
            for(auto adj:mp[ndval])
            {
                qu.push({tm+adj.second,adj.first});
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(mt[i]==INT_MAX)
                return -1;
            ans=max(ans,mt[i]);
        }
        return ans;
    }
};