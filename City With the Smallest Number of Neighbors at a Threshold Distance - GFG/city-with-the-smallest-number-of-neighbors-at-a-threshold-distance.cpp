//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,int distanceThreshold) 
    {
        vector<vector<int>> mat(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++)
        {
            mat[i][i]=0;
        }
        for(int i=0;i<edges.size();i++)
        {
            mat[edges[i][0]][edges[i][1]]=edges[i][2];
            mat[edges[i][1]][edges[i][0]]=edges[i][2];
        }
        for(int via=0;via<n;via++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    mat[i][j]=min(mat[i][j],mat[i][via]+mat[via][j]);
                }
            }
        }
        int ans=-1;
        int ansc=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int c=0;
            for(int j=0;j<n;j++)
            {
                // cout<<mat[i][j]<<" ";
                if(mat[i][j]<=distanceThreshold)
                {
                    c++;
                }
            }
            // cout<<"\n";
            if(c<=ansc)
            {
                ansc=c;
                ans=i;
            }
        }
        // cout<<"\n";
        return ans;
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
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends