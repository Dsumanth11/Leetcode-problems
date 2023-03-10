//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool DFS(int node,vector<int> &visited,vector<int> adj[],vector<int> &ans,vector<int> &pathvisit)
    {
        visited[node]=1;
        pathvisit[node]=1;
        for(auto x:adj[node])
        {
            if(visited[x]==0)
            {
                if(!DFS(x,visited,adj,ans,pathvisit))
                {
                    return false;
                }
            }
            else
            {
                if(pathvisit[x]==1)
                {
                    return false;
                }
            }
        }
        ans.push_back(node);
        pathvisit[node]=0;
        return true;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> ans;
        vector<int> pathvisit(V,0);
        vector<int> visited(V,0);
        for(int i=0;i<V;i++)
        {
            if(visited[i]==0)
            {
                DFS(i,visited,adj,ans,pathvisit);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends