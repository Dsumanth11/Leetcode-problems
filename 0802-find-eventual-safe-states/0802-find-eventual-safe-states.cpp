class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> indegree(graph.size(),0);
        map<int,vector<int>> mp;
        for(int i=0;i<graph.size();i++)
        {
            indegree[i]=graph[i].size();
            for(auto x:graph[i])
            {
                mp[x].push_back(i);
            }
        }
        queue<int> qu;
        for(int i=0;i<graph.size();i++)
        {
            if(indegree[i]==0)
            {
                qu.push(i);
            }
        }
        int ans=0;
        vector<int> ab;
        while(!qu.empty())
        {
            auto x=qu.front();
            ab.push_back(x);
            qu.pop();
            ans++;
            for(auto y:mp[x])
            {
                indegree[y]--;
                if(indegree[y]==0)
                {
                    qu.push(y);
                }
            }
        }
        sort(ab.begin(),ab.end());
        return ab;
    }
};