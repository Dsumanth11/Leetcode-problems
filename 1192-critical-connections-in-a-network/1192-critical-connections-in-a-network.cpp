class Solution {
public:
    vector<vector<int>> ans;
    void DFS(int node,vector<bool> &visited,map<int,vector<int>> &mp,vector<int> &sttime,
            vector<int> &lwstime,int &crtime,int par)
    {
        visited[node]=true;
        sttime[node]=crtime;
        lwstime[node]=crtime;
        crtime++;
        for(auto x:mp[node])
        {
            if(visited[x]==false && x!=par)
            {
                DFS(x,visited,mp,sttime,lwstime,crtime,node);
                lwstime[node]=min(lwstime[node],lwstime[x]);
                if(sttime[node]<lwstime[x])
                {
                    vector<int> temp;
                    temp.push_back(node);
                    temp.push_back(x);
                    ans.push_back(temp);
                }
            }
            else if(x!=par)
            {
                lwstime[node]=min(lwstime[node],lwstime[x]);
                if(sttime[node]<lwstime[x])
                {
                    vector<int> temp;
                    temp.push_back(node);
                    temp.push_back(x);
                    ans.push_back(temp);
                }
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> sttime(n+1),lwstime(n+1);
        ans.clear();
        map<int,vector<int>> mp;
        for(int i=0;i<connections.size();i++)
        {
            mp[connections[i][0]].push_back(connections[i][1]);
            mp[connections[i][1]].push_back(connections[i][0]);
        }
        vector<bool> visited(n,false);
        int crtime=1;
        DFS(0,visited,mp,sttime,lwstime,crtime,-1);
        return ans;
    }
};