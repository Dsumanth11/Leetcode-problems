//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class cmp
{
    public:
    bool operator()(pair<int,pair<int,int>> &a,pair<int,pair<int,int>> &b)
    {
        return a.first>b.first;
    }
};
class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        vector<vector<int>> dis(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        dis[0][0]=grid[0][0];
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,cmp> pq;
        pq.push({dis[0][0],{0,0}});
        int rows[]={-1,1,0,0};
        int cols[]={0,0,1,-1};
        while(!pq.empty())
        {
            auto x=pq.top();
            pq.pop();
            int x1=x.second.first;
            int y1=x.second.second;
            int crdis=x.first;
            for(int i=0;i<4;i++)
            {
                x1+=rows[i];
                y1+=cols[i];
                if(x1>=0 && x1<grid.size() && y1>=0 && y1<grid[0].size() && crdis+grid[x1][y1]<dis[x1][y1])
                {
                    dis[x1][y1]=crdis+grid[x1][y1];
                    pq.push({dis[x1][y1],{x1,y1}});
                }
                x1-=rows[i];
                y1-=cols[i];
            }
        }
        return dis[grid.size()-1][grid[0].size()-1];
    }
};




//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends