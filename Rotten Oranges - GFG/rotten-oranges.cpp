//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        queue<pair<int,int>> qu;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                    qu.push({i,j});
            }
        }
        int time=0;
        while(!qu.empty())
        {
            int t=qu.size();
            while(t--)
            {
                int i=qu.front().first;
                int j=qu.front().second;
                qu.pop();
                if(i-1>=0 && grid[i-1][j]==1)
                {
                    grid[i-1][j]=2;
                    qu.push({i-1,j});
                }
                if(j-1>=0 && grid[i][j-1]==1)
                {
                    grid[i][j-1]=2;
                    qu.push({i,j-1});
                }
                if(i+1<grid.size() && grid[i+1][j]==1)
                {
                    grid[i+1][j]=2;
                    qu.push({i+1,j});
                }
                if(j+1<grid[0].size() && grid[i][j+1]==1)
                {
                    grid[i][j+1]=2;
                    qu.push({i,j+1});
                }
            }
            if(qu.size()>0)
            {
                time++;
            }
        }
        bool chk=true;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                    chk=false;
            }
        }
        if(chk)
        return time;
        return -1;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends