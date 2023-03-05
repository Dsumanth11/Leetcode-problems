class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> qu;
        vector<vector<int>> ans(mat.size(),vector<int>(mat[0].size(),0));
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]==0)
                {
                    ans[i][j]=0;
                    qu.push({i,j});
                }
            }
        }
        int c=0;
        while(!qu.empty())
        {
            int k=qu.size();
            while(k--)
            {
                auto x=qu.front();
                qu.pop();
                ans[x.first][x.second]=c;
                mat[x.first][x.second]=0;
                if(x.first-1>=0 && mat[x.first-1][x.second]==1)
                {
                    mat[x.first-1][x.second]=0;
                    qu.push({x.first-1,x.second});
                }
                if(x.first+1<mat.size() && mat[x.first+1][x.second]==1)
                {
                    mat[x.first+1][x.second]=0;
                    qu.push({x.first+1,x.second});
                }
                if(x.second-1>=0 && mat[x.first][x.second-1]==1)
                {
                    mat[x.first][x.second-1]=0;
                    qu.push({x.first,x.second-1});
                }
                if(x.second+1<mat[0].size() && mat[x.first][x.second+1]==1)
                {
                    mat[x.first][x.second+1]=0;
                    qu.push({x.first,x.second+1});
                }
            }
            c++;
        }
        return ans;
    }
};