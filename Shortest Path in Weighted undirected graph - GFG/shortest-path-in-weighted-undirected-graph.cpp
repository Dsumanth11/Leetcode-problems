//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<int> dis(n+1,1e9);
        map<int,vector<pair<int,int>>> mp;
        for(int i=0;i<edges.size();i++)
        {
            mp[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            mp[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        dis[1]=0;
        vector<int> par(n+1,-1);
        queue<pair<int,int>> qu;
        qu.push({1,0});
        while(!qu.empty())
        {
            auto x=qu.front();
            qu.pop();
            int val=x.first;
            int ds=x.second;
            for(auto y:mp[val])
            {
                if(dis[y.first]>ds+y.second)
                {
                    dis[y.first]=y.second+ds;
                    par[y.first]=val;
                    qu.push({y.first,dis[y.first]});
                }
            }
        }
        vector<int> ans;
        int node=n;
        bool first=false;
        while(node!=-1)
        {
            ans.push_back(node);
            node=par[node];
        }
        if(ans[ans.size()-1]==1)
        {
            reverse(ans.begin(),ans.end());
        }
        else
        {
            ans.clear();
            ans.push_back(-1);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends