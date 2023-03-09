//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    pair<int,int> findUltimateCell(pair<int,int> a,vector<vector<pair<int,int>>> &dis)
    {
        int crx=a.first;
        int cry=a.second;
        a.first=dis[crx][cry].first;
        a.second=dis[crx][cry].second;
        if(a.first==crx && a.second==cry)
        {
            return a;
        }
        return dis[crx][cry]=findUltimateCell(a,dis);
    }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        vector<int> add={1,0,-1,-2,-3};
        int ans=0;
        vector<vector<pair<int,int>>> dis(n,vector<pair<int,int>>(m,{0,0}));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                dis[i][j]={i,j};
            }
        }
        vector<int> re;
        vector<vector<int>> wa_la(n,vector<int>(m,0));
        for(int i=0;i<operators.size();i++)
        {
            int x=operators[i][0];
            int y=operators[i][1];
            if(wa_la[x][y]==1)
            {
                
            }
            else
            {
                wa_la[x][y]=1;
                set<pair<int,int>> st;
                if(x-1>=0 && wa_la[x-1][y]==1)
                {
                    st.insert(findUltimateCell({x-1,y},dis));
                }
                if(y-1>=0 && wa_la[x][y-1]==1)
                {
                    st.insert(findUltimateCell({x,y-1},dis));
                }
                if(x+1<n && wa_la[x+1][y]==1)
                {
                    st.insert(findUltimateCell({x+1,y},dis));
                }
                if(y+1<m && wa_la[x][y+1]==1)
                {
                    st.insert(findUltimateCell({x,y+1},dis));
                }
                ans+=add[st.size()];
                if(st.size()>0)
                {
                    for(auto tp:st)
                    {
                        dis[tp.first][tp.second]={x,y};
                    }
                }
            }
            re.push_back(ans);
        }
        return re;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends