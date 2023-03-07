class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& p) {
        vector<int> indegree(numCourses,0);
        map<int,vector<int>> mp;
        for(int i=0;i<p.size();i++)
        {
            indegree[p[i][0]]+=1;
            mp[p[i][1]].push_back(p[i][0]);
        }
        queue<int> qu;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            {
                qu.push(i);
            }
        }
        vector<int> ans;
        while(!qu.empty())
        {
            int frnt=qu.front();
            ans.push_back(frnt);
            qu.pop();
            for(auto x:mp[frnt])
            {
                indegree[x]--;
                if(indegree[x]==0)
                {
                    qu.push(x);
                }
            }
        }
        if(ans.size()!=numCourses)
        {
            ans.clear();
        }
        return ans;
    }
};