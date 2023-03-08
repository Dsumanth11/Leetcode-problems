//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // Code here
        vector<int> cost(n+1,INT_MAX);
        map<int,vector<pair<int,int>>> mp;
        for(int i=0;i<flights.size();i++)
        {
            mp[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        queue<pair<int,int>> pq;
        pq.push({0,src});
        cost[src]=0;
        int j=0;
        while(!pq.empty() && K>=0)
        {
            j++;
            // cout<<j<<":\n";
            int sz=pq.size();
            K--;
            while(sz--)
            {
                auto x=pq.front();
                pq.pop();
                int crindx=x.second;
                int crcost=x.first;
                for(auto temp:mp[crindx])
                {
                    if(crcost+temp.second<cost[temp.first])
                    {
                        cost[temp.first]=crcost+temp.second;
                        // cout<<"{"<<cost[temp.first]<<","<<temp.first<<"}\n";
                        pq.push({cost[temp.first],temp.first});
                    }
                }
            }
        }
        if(cost[dst]==INT_MAX)
        {
            cost[dst]=-1;
        }
        return cost[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends