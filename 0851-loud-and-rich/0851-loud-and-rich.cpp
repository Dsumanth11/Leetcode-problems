class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        map<int,vector<int>> mp;
        for(int i=0;i<richer.size();i++)
        {
            mp[richer[i][0]].push_back(richer[i][1]);
        }
        vector<int> indegree(quiet.size(),0);
        for(auto x:richer)
        {
            indegree[x[1]]++;
        }
        queue<int> pq;
        vector<int> ansq;
        for(int i=0;i<quiet.size();i++)
        {
            ansq.push_back(i);
        }
        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i]==0)
            {
                pq.push(i);
            }
        }
        while(!pq.empty())
        {
            auto tp=pq.front();
            pq.pop();
            for(auto x:mp[tp])
            {
                indegree[x]--;
                if(indegree[x]==0)
                {
                    pq.push(x);
                }
                if(quiet[ansq[x]]>quiet[ansq[tp]])
                {
                    ansq[x]=ansq[tp];
                }
            }
        }
        return ansq;
    }
};