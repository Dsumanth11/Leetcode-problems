#define mat grid
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        queue<pair<int,int>> qu;
        int col=grid[0].size();
        int row=grid.size();
        set<pair<int,int>> visited;
        for(int i=0;i<grid.size();i++)
        {
            if(grid[i][0]==1)
            {
                qu.push({i,0});
                visited.insert({i,0});
            }
            if(col>1 && grid[i][col-1]==1)
            {
                qu.push({i,col-1});
                visited.insert({i,col-1});
            }
        }
        for(int i=0;i<grid[0].size();i++)
        {
            if(grid[0][i]==1)
            {
                qu.push({0,i});
                visited.insert({0,i});
            }
            if(grid.size()>1 && grid[row-1][i]==1)
            {
                qu.push({row-1,i});
                visited.insert({row-1,i});
            }
        }
        while(!qu.empty())
        {
            int x=qu.front().first;
            int y=qu.front().second;
            qu.pop();
            if(x-1>=0 && visited.find({x-1,y})==visited.end() && mat[x-1][y]==1)
            {
                visited.insert({x-1,y});
                qu.push({x-1,y});
            }
            if(y-1>=0 && visited.find({x,y-1})==visited.end() && mat[x][y-1]==1)
            {
                visited.insert({x,y-1});
                qu.push({x,y-1});
            }
            if(x+1<mat.size() && visited.find({x+1,y})==visited.end() && mat[x+1][y]==1)
            {
                visited.insert({x+1,y});
                qu.push({x+1,y});
            }
            if(y+1<mat[0].size() && visited.find({x,y+1})==visited.end() && mat[x][y+1]==1)
            {
                visited.insert({x,y+1});
                qu.push({x,y+1});
            }
        }
        int ans=0;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]==0)
                {
                    continue;
                }
                else 
                {
                    if(visited.find({i,j})!=visited.end())
                    {
                        
                    }
                    else
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};