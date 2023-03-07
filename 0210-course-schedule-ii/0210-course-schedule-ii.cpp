class Solution {
public:
    bool DFS(int val,stack<int> &stk,map<int,vector<int>> &mp,vector<int> &visited,vector<int> &crvisit)
    {
        visited[val]=1;
        crvisit[val]=1;
        for(auto x:mp[val])
        {
            if(visited[x]==1)
            {
                if(crvisit[x]==1)
                {
                    for(auto y:mp[val])
                    {
                        crvisit[y]=1;
                        visited[y]=1;
                    }
                    return false;
                }
            }
            else
            {
                if(!DFS(x,stk,mp,visited,crvisit))
                {
                    for(auto y:mp[val])
                    {
                        crvisit[y]=1;
                        visited[y]=1;
                    }
                    return false;
                }
            }
        }
        crvisit[val]=0;
        stk.push(val);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        stack<int> stk;
        map<int,vector<int>> mp;
        for(int i=0;i<pre.size();i++)
        {
            mp[pre[i][1]].push_back(pre[i][0]);
        }
        // for(auto x:mp)
        // {
        //     // cout<<x.first<<" : ";
        //     for(auto y:x.second)
        //     {
        //         cout<<y<<" ";
        //     }
        //     cout<<"\n";
        // }
        vector<int> visited(numCourses,0);
        vector<int> crvisit(numCourses,0);
        for(int i=0;i<numCourses;i++)
        {
            if(visited[i]==0)
            {
                DFS(i,stk,mp,visited,crvisit);
            }
            // for(auto x:visited)
            // {
            //     cout<<x<<" ";
            // }
            // cout<<"\n";
            // for(auto x:crvisit)
            // {
            //     cout<<x<<" ";
            // }
            // cout<<"\n";
            // cout<<stk.size()<<"\n\n";
        }
        vector<int> ans;
        while(!stk.empty())
        {
            if(crvisit[stk.top()]==0)
                ans.push_back(stk.top());
            stk.pop();
        }
        if(ans.size()!=numCourses)
        {
            ans.clear();
        }
        return ans;
    }
};