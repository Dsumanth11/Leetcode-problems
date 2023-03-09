class Solution {
public:
    int findUltimateParent(int node,vector<int> &parent)
    {
        if(node==parent[node])
            return node;
        return parent[node]=findUltimateParent(parent[node],parent);
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string,int> mp;
        vector<int> parent(accounts.size(),0);
        vector<int> size(accounts.size(),0);
        for(int i=0;i<accounts.size();i++)
        {
            parent[i]=i;
        }
        for(int i=0;i<accounts.size();i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                if(mp.find(accounts[i][j])==mp.end())
                {
                    mp[accounts[i][j]]=i;
                }
                else
                {
                    int ulp1=findUltimateParent(i,parent);
                    int ulp2=findUltimateParent(mp[accounts[i][j]],parent);
                    if(size[ulp1]<size[ulp2])
                    {
                        parent[ulp1]=ulp2;
                    }
                    else if(size[ulp1]>size[ulp2])
                    {
                        parent[ulp2]=ulp1;
                    }
                    else
                    {
                        size[ulp1]++;
                        parent[ulp2]=ulp1;   
                    }
                }
            }
        }
        vector<set<string>> vc(accounts.size());
        for(int i=0;i<accounts.size();i++)
        {
            int ndval=findUltimateParent(i,parent);
            for(int j=1;j<accounts[i].size();j++)
            {
                vc[ndval].insert(accounts[i][j]);
            }
        }
        vector<vector<string>> ans;
        for(int i=0;i<vc.size();i++)
        {
            if(vc[i].size()>0)
            {
                vector<string> ab;
                ab.push_back(accounts[i][0]);
                for(auto x:vc[i])
                {
                    ab.push_back(x);
                }
                ans.push_back(ab);
            }
        }
        return ans;
    }
};