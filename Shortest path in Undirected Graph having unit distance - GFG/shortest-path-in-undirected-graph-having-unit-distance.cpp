//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int> dis(N,INT_MAX);
        map<int,vector<int>> mp;
        for(int i=0;i<edges.size();i++)
        {
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
        }
        queue<pair<int,int>> qu;
        qu.push({src,0});
        dis[src]=0;
        while(!qu.empty())
        {
            auto x=qu.front();
            int ele=x.first;
            int crdis=x.second;
            for(auto y:mp[ele])
            {
                if(dis[y]>crdis+1)
                {
                    dis[y]=crdis+1;
                    qu.push({y,crdis+1});
                }
            }
            qu.pop();
        }
        for(auto &x:dis)
        {
            if(x==INT_MAX)
            {
                x=-1;
            }
        }
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends