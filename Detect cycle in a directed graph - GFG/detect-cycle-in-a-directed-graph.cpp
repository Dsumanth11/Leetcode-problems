//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool DFS(int nd,unordered_set<int> &visit,unordered_set<int> &crvisit,vector<int> adj[])
    {
        visit.insert(nd);
        crvisit.insert(nd);
        for(auto it:adj[nd])
        {
            if(visit.find(it)==visit.end())
            {
                if(DFS(it,visit,crvisit,adj))
                    return true;
            }
            else
            {
                if(crvisit.find(it)!=crvisit.end())
                    return true;
            }
        }
        crvisit.erase(nd);
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        bool ans=false;
        unordered_set<int> visit,crvisit;
        for(int i=0;i<V;i++)
        {
            if(visit.find(i)==visit.end())
            {
                ans=DFS(i,crvisit,visit,adj);
            }
            if(ans)
            {
                return ans;
            }
        }
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
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends