//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void solve(int r,int c,int initial_color,int newColor,vector<vector<int>>& image,vector<vector<int>> &dp)
    {
        if(r<0 || r>=image.size() || c<0 || c>=image[0].size())
        {
            return ;
        }
        if(dp[r][c]==1)
        {
            return ;
        }
        if(image[r][c]==initial_color && dp[r][c]==-1)
        {
            image[r][c]=newColor;
            dp[r][c]=1;
            solve(r-1,c,initial_color,newColor,image,dp);
            solve(r+1,c,initial_color,newColor,image,dp);
            solve(r,c-1,initial_color,newColor,image,dp);
            solve(r,c+1,initial_color,newColor,image,dp);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int initial_color=image[sr][sc];
        vector<vector<int>> dp(image.size(),vector<int>(image[0].size(),-1));
        solve(sr,sc,initial_color,newColor,image,dp);
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends