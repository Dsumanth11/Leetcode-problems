class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        map<int,vector<int>> mp;
        vector<vector<int>> adj(n,vector<int>(n,0));
        for(int i=0;i<roads.size();i++)
        {
            adj[roads[i][0]][roads[i][1]]=1;
            adj[roads[i][1]][roads[i][0]]=1;
            mp[roads[i][0]].push_back(roads[i][1]);
            mp[roads[i][1]].push_back(roads[i][0]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int crans=mp[i].size()+mp[j].size();
                if(adj[i][j]==1)
                {
                    crans--;
                }
                ans=max(ans,crans);
            }
        }
        return ans;
    }
};