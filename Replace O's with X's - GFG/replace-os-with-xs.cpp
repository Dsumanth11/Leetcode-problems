//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        queue<pair<int,int>> qu;
        set<pair<int,int>> visited;
        for(int i=0;i<n;i++)
        {
            if(mat[i][0]=='O')
            {
                qu.push({i,0});
                visited.insert({i,0});
            }
            if(m>1 && mat[i][m-1]=='O')
            {
                qu.push({i,m-1});
                visited.insert({i,m-1});
            }
        }
        for(int i=0;i<m;i++)
        {
            if(mat[0][i]=='O')
            {
                qu.push({0,i});
                visited.insert({0,i});
            }
            if(n>1 && mat[n-1][i]=='O')
            {
                qu.push({n-1,i});
                visited.insert({n-1,i});
            }
        }
        while(!qu.empty())
        {
            auto tp=qu.front();
            qu.pop();
            int x=tp.first;
            int y=tp.second;
            if(x-1>=0 && visited.find({x-1,y})==visited.end() && mat[x-1][y]=='O')
            {
                visited.insert({x-1,y});
                qu.push({x-1,y});
            }
            if(x+1<mat.size() && visited.find({x+1,y})==visited.end() && mat[x+1][y]=='O')
            {
                visited.insert({x+1,y});
                qu.push({x+1,y});
            }
            if(y-1>=0 && visited.find({x,y-1})==visited.end() && mat[x][y-1]=='O')
            {
                visited.insert({x,y-1});
                qu.push({x,y-1});
            }
            if(y+1<mat[0].size() && visited.find({x,y+1})==visited.end() && mat[x][y+1]=='O')
            {
                visited.insert({x,y+1});
                qu.push({x,y+1});
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]!='X')
                {
                    if(visited.find({i,j})==visited.end())
                    {
                        mat[i][j]='X';
                    }
                }
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends