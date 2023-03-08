//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class cmp
{
    public:
    bool operator()(pair<pair<int,int>,int> &a,pair<pair<int,int>,int> &b)
    {
            return a.second>b.second;
    }
};
class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        vector<vector<int>> dis(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,cmp> pq;
        if(grid[source.first][source.second]==0)
        {
            return -1;
        }
        dis[source.first][source.second]=0;
        pq.push({{source.first,source.second},0});
        // cout<<pq.top().first.first<<" "<<pq.top().first.second<<" "<<pq.top().second<<"\n";
        while(!pq.empty())
        {
            auto x=pq.top();
            pq.pop();
            int x1=x.first.first;
            int y1=x.first.second;
            int crdis=x.second;
            if(x1-1>=0 && grid[x1-1][y1]==1 && crdis+1<dis[x1-1][y1])
            {
                dis[x1-1][y1]=crdis+1;
                pq.push({{x1-1,y1},crdis+1});
            }
            if(y1-1>=0 && grid[x1][y1-1]==1 && crdis+1<dis[x1][y1-1])
            {
                dis[x1][y1-1]=crdis+1;
                pq.push({{x1,y1-1},crdis+1});
            }
            if(x1+1<grid.size() && grid[x1+1][y1]==1 && crdis+1<dis[x1+1][y1])
            {
                dis[x1+1][y1]=crdis+1;
                pq.push({{x1+1,y1},crdis+1});
            }
            if(y1+1<grid[0].size() && grid[x1][y1+1]==1 && crdis+1<dis[x1][y1+1])
            {
                dis[x1][y1+1]=crdis+1;
                pq.push({{x1,y1+1},crdis+1});
            }
        }
        if(dis[destination.first][destination.second]==INT_MAX)
        {
            dis[destination.first][destination.second]=-1;
        }
        return dis[destination.first][destination.second];
    }
};


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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends