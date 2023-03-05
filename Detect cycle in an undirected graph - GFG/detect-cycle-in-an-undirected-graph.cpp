//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    void BFS(int val,set<int> &visited,vector<int> adj[],bool &ans)
    {
        visited.insert(val);
        queue<pair<int,int>> qu;
        qu.push({val,-1});
        while(!qu.empty())
        {
            int k=qu.size();
            while(k--)
            {
                int nod=qu.front().first;
                int par=qu.front().second;
                qu.pop();
                for(auto x:adj[nod])
                {
                    if(x!=par)
                    {
                        if(visited.find(x)==visited.end())
                        {
                            visited.insert(x);
                            qu.push({x,nod});
                        }
                        else
                        {
                            ans=true;
                            return ;
                        }
                    }
                }
            }
        }
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code her
        map<int,vector<int>> mp;
        set<int> visited;
        bool ans=false;
        for(int i=0;i<V;i++)
        {
            if(visited.find(i)==visited.end())
            {
                BFS(i,visited,adj,ans);
            }
            if(ans)
            return ans;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends