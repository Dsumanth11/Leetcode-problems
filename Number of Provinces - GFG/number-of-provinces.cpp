//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int findUltimatePar(int node,vector<int> &par)
    {
        if(par[node]==node)
            return node;
        return par[node]=findUltimatePar(par[node],par);
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        queue<pair<int,int>> qu;
        for(int i=0;i<adj.size();i++)
        {
            for(int j=i+1;j<adj[i].size();j++)
            {
                if(adj[i][j]==1 && i!=j)
                {
                    qu.push({i+1,j+1});
                    // cout<<i+1<<" "<<j+1<<"\n";
                }
            }
        }
        vector<int> parent(V+1);
        for(int i=0;i<=V;i++)
        {
            parent[i]=i;
        }
        vector<int> size(V+1,1);
        while(!qu.empty())
        {
            auto x=qu.front();
            qu.pop();
            int n1=x.first;
            int n2=x.second;
            int ulp1=findUltimatePar(n1,parent);
            int ulp2=findUltimatePar(n2,parent);
            if(ulp1==ulp2)
            {
                continue;
            }
            else
            {
                if(size[ulp1]<size[ulp2])
                {
                    size[ulp2]+=size[ulp1];
                    parent[ulp1]=ulp2;
                }
                else
                {
                    size[ulp1]+=size[ulp2];
                    parent[ulp2]=ulp1;
                }
            }
        }
        int c=0;
        set<int> st;
        for(int i=1;i<=V;i++)
        {
            parent[i]=findUltimatePar(i,parent);
            if(parent[i]==i)
            {
                c++;
            }
        }
        return c;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends