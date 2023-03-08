//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#define md 1000000007
class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        map<long long int,vector<pair<long long int,long long int>>> mp;
        for(long long int i=0;i<roads.size();i++)
        {
            roads[i][2]%=md;
            mp[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            mp[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        vector<long long int> paths(n+1,0);
        vector<long long int> dis(n+1,LLONG_MAX);
        priority_queue<pair<long long int,long long int>,vector<pair<long long int,long long int>>,greater<pair<long long int,long long int>>> pq;
        dis[0]=0;
        paths[0]=1;
        pq.push({0,0});
        while(!pq.empty())
        {
            auto x=pq.top();
            pq.pop();
            long long int crtime=x.first;
            long long int nval=x.second;
            for(auto y:mp[nval])
            {
                if(crtime+y.second<dis[y.first])
                {
                    dis[y.first]=crtime+y.second;
                    pq.push({dis[y.first],y.first});
                    paths[y.first]=paths[nval]%md;
                    paths[y.first]%=md;
                }
                else if(crtime+y.second==dis[y.first])
                {
                    paths[y.first]+=(paths[nval]%md);
                    paths[y.first]%=md;
                }
            }
        }
        return (int)paths[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends