//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findUltimateParent(int node,vector<int> &par)
    {
        if(par[node]==node)
            return node;
        par[node]=findUltimateParent(par[node],par);
        return par[node];
    }
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        if(edge.size()<n-1)
        {
            return -1;
        }
        vector<int> size(n+1,1);
        vector<int> parent(n+1,0);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
        int cnt=0;
        for(int i=0;i<edge.size();i++)
        {
            int n1=edge[i][0];
            int n2=edge[i][1];
            int ulp1=findUltimateParent(n1,parent);
            int ulp2=findUltimateParent(n2,parent);
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
        for(int i=0;i<=n-1;i++)
        {
            parent[i]=findUltimateParent(i,parent);
            if(parent[i]==i)
            {
                cnt++;
            }
        }
        return cnt-1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends