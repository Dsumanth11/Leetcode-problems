//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
// #include <bits
class Solution {
  public:
    void DFS(int val,map<int,vector<pair<int,int>>> &mp,set<int> &visited,stack<int> &topo)
    {
        visited.insert(val);
        for(auto x:mp[val])
        {
            if(visited.find(x.first)==visited.end())
            {
                DFS(x.first,mp,visited,topo);
            }
        }
        topo.push(val);
        return ;
    }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        map<int,vector<pair<int,int>>> mp;
        for(int i=0;i<edges.size();i++)
        {
            mp[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        // find the topological sort using DFS
        set<int> visited;
        stack<int> toposort;
        for(int i=0;i<N;i++)
        {
            if(visited.find(i)==visited.end())
            {
                DFS(i,mp,visited,toposort);
            }
        }
        vector<int> dis(N,INT_MAX);
        dis[0]=0;
        while(!toposort.empty())
        {
            int it=toposort.top();
            // cout<<it<<" ";
            toposort.pop();
            if(dis[it]==INT_MAX)
            {
                dis[it]=-1;
            }
            for(auto y:mp[it])
            {
                if(dis[it]!=-1)
                {            
                    int cr=dis[it]+y.second;
                    dis[y.first]=min(cr,dis[y.first]);
                }
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
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