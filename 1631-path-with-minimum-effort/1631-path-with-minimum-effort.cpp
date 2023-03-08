class cmp
{
    public:
    bool operator()(pair<int,pair<int,int>> &a,pair<int,pair<int,int>> &b)
    {
        return a.first>b.first;
    }
};
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<int>> dis(heights.size(),vector<int>(heights[0].size(),INT_MAX));
        dis[0][0]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,cmp> pq;
        pq.push({0,{0,0}});
        vector<int> row={0,0,1,-1};
        vector<int> cols={1,-1,0,0};
        while(!pq.empty())
        {
            auto x=pq.top();
            pq.pop();
            int x1=x.second.first;
            int fixedx=x1;
            int y1=x.second.second;
            int fixedy=y1;
            int crdis=x.first;
            for(int i=0;i<4;i++)
            {
                x1=fixedx+row[i];
                y1=fixedy+cols[i];
                
                if(x1>=0 && x1<heights.size() && y1>=0 && y1<heights[0].size() && 
                   max(crdis,abs(heights[x1][y1]-heights[fixedx][fixedy]))<dis[x1][y1])
                {
                    dis[x1][y1]=max(crdis,abs(heights[x1][y1]-heights[fixedx][fixedy]));
                    pq.push({dis[x1][y1],{x1,y1}});
                }
            }
        }
        return dis[heights.size()-1][heights[0].size()-1];
    }
};