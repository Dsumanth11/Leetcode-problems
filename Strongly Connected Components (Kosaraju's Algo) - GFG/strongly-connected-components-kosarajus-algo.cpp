//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void DFS(int node,vector<bool> &visited,stack<int> &stk,vector<vector<int>> &adj)
	{
	    visited[node]=true;
	    for(auto x:adj[node])
	    {
	        if(visited[x]==false)
	        DFS(x,visited,stk,adj);
	    }
	    stk.push(node);
	}
	void DFS1(int node,vector<bool> &visited,vector<vector<int>> &adj)
	{
	    visited[node]=true;
	    for(auto x:adj[node])
	    {
	        if(visited[x]==false)
	        {
	            DFS1(x,visited,adj);
	        }
	    }
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        stack<int> stk;
        vector<bool> visited(V+1,false);
        for(int i=0;i<V;i++)
        {
            if(visited[i]==false)
            {
                DFS(i,visited,stk,adj);
            }
        }
        vector<vector<int>> newadj(V);
        for(int i=0;i<V;i++)
        {
            visited[i]=false;
            for(auto it:adj[i])
            {
                newadj[it].push_back(i);
            }
        }
        int c=0;
        while(!stk.empty())
        {
            int node=stk.top();
            stk.pop();
            if(!visited[node])
            {
                DFS1(node,visited,newadj);
                c++;
            }
        }
        return c;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends