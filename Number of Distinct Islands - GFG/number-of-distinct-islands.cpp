//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void DFS(int r,int c,set<pair<int,int>> &vis,vector<pair<int,int>> &tp,int str,int stc,vector<vector<int>>& grid)
  {
      if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size() || grid[r][c]==0)
      {
          return ;
      }
      vis.insert({r,c});
      tp.push_back({r-str,c-stc});
      if(r-1>=0 && vis.find({r-1,c})==vis.end())
      {
          DFS(r-1,c,vis,tp,str,stc,grid);
      }
      if(r+1<grid.size() && vis.find({r+1,c})==vis.end())
      {
          DFS(r+1,c,vis,tp,str,stc,grid);
      }
      if(c-1>=0 && vis.find({r,c-1})==vis.end())
      {
          DFS(r,c-1,vis,tp,str,stc,grid);
      }
      if(c+1<grid[0].size() && vis.find({r,c+1})==vis.end())
      {
          DFS(r,c+1,vis,tp,str,stc,grid);
      }
  }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        set<pair<int,int>> visited;
        set<vector<pair<int,int>>> st;
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1 && visited.find({i,j})==visited.end())
                {
                    vector<pair<int,int>> tp;
                    DFS(i,j,visited,tp,i,j,grid);
                    st.insert(tp);
                }
            }
        }
        return st.size();
    }
};
// // 
// -1 1 0 0 0 
// 1 1 0 0 0
// 0 0 0 1 1
// 0 0 0 1 1


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends