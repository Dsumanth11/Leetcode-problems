class Solution {
public:
    double distance(int x1, int y1, int x2, int y2)
    {
        // Calculating distance
        double ans=sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0);
        return ans;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        vector<vector<int>> dis(bombs.size()+3,vector<int>(bombs.size()+3,1e8));
        for(int i=0;i<bombs.size();i++)
        {
            dis[i][i]=0;
        }
        for(int i=0;i<bombs.size();i++)
        {
            for(int j=i+1;j<bombs.size();j++)
            {
                int x1=bombs[i][0];
                int y1=bombs[i][1];
                int r1=bombs[i][2];
                int x2=bombs[j][0];
                int y2=bombs[j][1];
                int r2=bombs[j][2];
                if(distance(x1,y1,x2,y2)<=r1)
                {
                    dis[i][j]=0;
                }
                if(distance(x1,y1,x2,y2)<=r2)
                {
                    dis[j][i]=0;
                }
            }
        }
        for(int via=0;via<bombs.size();via++)
        {
            for(int i=0;i<bombs.size();i++)
            {
                for(int j=0;j<bombs.size();j++)
                {
                    if(dis[i][j]>(dis[i][via]+dis[via][j]))
                    {
                        dis[i][j]=(dis[i][via]+dis[via][j]);
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<dis.size();i++)
        {
            int cr=0;
            for(int j=0;j<dis[i].size();j++)
            {
                if(dis[i][j]<1e8)
                {
                    cr++;
                }
            }
            ans=max(cr,ans);
        }
        return ans;
    }
};