class Solution {
public:
    int findUltimateParent(int node,vector<int> &parent)
    {
        if(node==parent[node])
            return node;
        return parent[node]=findUltimateParent(parent[node],parent);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent(edges.size()+2,0);
        vector<int> ss(edges.size()+2,1);
        for(int i=1;i<=edges.size();i++)
        {
            parent[i]=i;
        }
        vector<int> ans;
        for(auto x:edges)
        {
            int n1=x[0];
            int n2=x[1];
            int p1=findUltimateParent(n1,parent);
            int p2=findUltimateParent(n2,parent);
            if(p1==p2)
            {
                ans.clear();
                ans.push_back(x[0]);
                ans.push_back(x[1]);
            }
            else
            {
                if(ss[p1]>ss[p2])
                {
                    parent[p2]=p1;
                }
                else if(ss[p2]>ss[p1])
                {
                    parent[p1]=p2;
                }
                else
                {
                    parent[p2]=p1;
                    ss[p1]+=1;
                }
            }
        }
        return ans;
    }
};