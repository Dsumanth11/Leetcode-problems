class Solution {
public:
    bool DFS(int nd,vector<int> &visit,vector<int> &crvisit,vector<vector<int>>& graph)
    {
        visit[nd]=1;
        crvisit[nd]=1;
        for(auto x:graph[nd])
        {
            if(crvisit[x]==1)
            {
                return false;
            }
            else if(crvisit[x]==0 && visit[x]==0)
            {
                if(!DFS(x,visit,crvisit,graph))
                    return false;
            }
        }
        crvisit[nd]=0;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> visit(graph.size(),0);
        vector<int> crvisit(graph.size(),0);
        for(int i=0;i<graph.size();i++)
        {
            if(visit[i]==0)
            {
                DFS(i,visit,crvisit,graph);
            }
        }
        vector<int> ans;
        for(int i=0;i<crvisit.size();i++)
        {
            if(crvisit[i]==0)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};