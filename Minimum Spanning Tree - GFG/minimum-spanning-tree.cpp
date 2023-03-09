//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

struct abc
{
    int wt;
    int n1;
    int n2;
};
struct cmp
{
    bool operator()(pair<int,pair<int,int>> &a,pair<int,pair<int,int>> &b)
    {
        return a.first>b.first;
    }
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int findUPnode(int node,vector<int> par)
	{
	    if(par[node]==node)
	        return node;
	    return par[node]=findUPnode(par[node],par);
	}
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,cmp> pq;
        vector<int> par(V+1);
        vector<int> size(V+1,1);
        for(int i=1;i<=V;i++)
        {
            par[i]=i;
        }
        for(int i=0;i<V;i++)
        {
            for(auto x:adj[i])
            {
                pq.push({x[1],{i,x[0]}});
            }
        }
        int sum=0;
        while(!pq.empty())
        {
            auto x=pq.top();
            pq.pop();
            int n1=x.second.first;
            int n2=x.second.second;
            int ulp1=findUPnode(n1,par);
            int ulp2=findUPnode(n2,par);
            if(ulp1==ulp2)
            {
                continue;
            }
            else
            {
                sum+=x.first;
                if(size[ulp1]<size[ulp2])
                {
                    size[ulp2]+=size[ulp1];
                    par[ulp1]=ulp2;
                }
                else
                {
                    size[ulp1]+=size[ulp2];
                    par[ulp2]=ulp1;
                }
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends