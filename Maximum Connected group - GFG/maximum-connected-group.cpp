//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    pair<int,int> findUltimateParent(pair<int,int> cr,vector<vector<pair<int,int>>> &par)
    {
        int crx=cr.first;
        int cry=cr.second;
        cr.first=par[crx][cry].first;
        cr.second=par[crx][cry].second;
        if(crx==cr.first && cry==cr.second)
        {
            return cr;
        }
        return par[crx][cry]=findUltimateParent(cr,par);
    }
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        vector<vector<pair<int,int>>> par(grid.size(),vector<pair<int,int>>(grid[0].size(),{0,0}));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                par[i][j]={i,j};
            }
        }
        vector<vector<int>> ans(grid.size(),vector<int>(grid[0].size(),0));
        int cr=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    ans[i][j]=1;
                    set<pair<int,int>> st;
                    if(i-1>=0 && grid[i-1][j]==1)
                    {
                        st.insert(findUltimateParent({i-1,j},par));
                    }
                    if(j-1>=0 and grid[i][j-1]==1)
                    {
                        st.insert(findUltimateParent({i,j-1},par));
                    }
                    for(auto tp:st)
                    {
                        ans[i][j]+=ans[tp.first][tp.second];
                        par[tp.first][tp.second]={i,j};
                    }
                    cr=max(cr,ans[i][j]);
                }
            }
        }
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==0)
                {
                    int crans=1;
                    set<pair<int,int>> st;
                    if(i-1>=0 && grid[i-1][j]==1)
                    {
                        st.insert(findUltimateParent({i-1,j},par));
                    }
                    if(j-1>=0 and grid[i][j-1]==1)
                    {
                        st.insert(findUltimateParent({i,j-1},par));
                    }
                    if(i+1<grid.size() && grid[i+1][j]==1)
                    {
                        st.insert(findUltimateParent({i+1,j},par));
                    }
                    if(j+1<grid[0].size() and grid[i][j+1]==1)
                    {
                        st.insert(findUltimateParent({i,j+1},par));
                    }
                    for(auto tp:st)
                    {
                        crans+=ans[tp.first][tp.second];
                    }
                    cr=max(crans,cr);
                }
            }
        }
        return cr;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends