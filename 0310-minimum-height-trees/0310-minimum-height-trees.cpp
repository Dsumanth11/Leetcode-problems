class Solution {
public:
    int crheight=INT_MAX;
    vector<int> crans;
    int findHeight(int node,vector<int> &heights,map<int,vector<int>> &mp,int par)
    {
        heights[node]=1;
        int crhe=0;
        for(auto x:mp[node])
        {
            if(x!=par)
            {
                crhe=max(crhe,findHeight(x,heights,mp,node));
            }
        }
        heights[node]+=crhe;
        return heights[node];
    }
    void DFS(int node,vector<int> &heights,map<int,vector<int>> &mp,int par,int parheight)
    {
        vector<int> crh;
        vector<int> pfx;
        for(auto x:mp[node])
        {
            if(x==par)
            {
                crh.push_back(0);
            }
            else
            {
                crh.push_back(heights[x]);
            }
            if(pfx.size()==0)
            {
                pfx.push_back(0);
            }
            else
            {
                pfx.push_back(max(pfx[pfx.size()-1],crh[pfx.size()-1]));
            }
        }
        vector<int> sfx(pfx.size(),0);
        for(int i=pfx.size()-2;i>=0;i--)
        {
            sfx[i]=max(sfx[i+1],crh[i+1]);
        }
        int htoftree=max(parheight+1,heights[node]);
        if(htoftree==crheight)
        {
            crans.push_back(node);
            // crans++;
        }
        if(htoftree<crheight)
        {
            crheight=htoftree;
            crans.clear();
            crans.push_back(node);
        }
        for(int i=0;i<mp[node].size();i++)
        {
            if(mp[node][i]==par)
            {
                continue;
            }
            else
            {
                int hght1=max(max(pfx[i],sfx[i]),parheight)+1;
                DFS(mp[node][i],heights,mp,node,hght1);
            }
        }
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        crheight=INT_MAX;
        crans.clear();
        vector<int> heights(n,-1);
        map<int,vector<int>> mp;
        for(int i=0;i<edges.size();i++)
        {
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
        }
        findHeight(0,heights,mp,-1);
        DFS(0,heights,mp,-1,0);
        return crans;
    }
};