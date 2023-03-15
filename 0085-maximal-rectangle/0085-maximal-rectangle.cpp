class Solution {
public:
    int maxRectangleArea(vector<int> &nums)
    {
        vector<int> suffix(nums.size(),nums.size()),prefix(nums.size(),-1);
        stack<int> stk;
        for(int i=0;i<nums.size();i++)
        {
            if(!stk.empty())
            {
                while(!stk.empty() && nums[stk.top()]>nums[i])
                {
                    suffix[stk.top()]=i;
                    stk.pop();
                }
            }
            stk.push(i);
        }
        while(!stk.empty())
        {
            stk.pop();
        }
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(!stk.empty())
            {
                while(!stk.empty() && nums[stk.top()]>nums[i])
                {
                    prefix[stk.top()]=i;
                    stk.pop();
                }
            }
            stk.push(i);
        }
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            int crans=nums[i]*(i-prefix[i]);
            crans+=nums[i]*(suffix[i]-i-1);
            ans=max(crans,ans);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> tp;
        for(auto x:matrix[0])
        {
            if(x=='0')
            {
                tp.push_back(0);
            }
            else
            {
                tp.push_back(1);
            }
        }
        int ans=0;
        ans=maxRectangleArea(tp);
        for(int i=1;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]=='1')
                {
                    tp[j]+=1;
                }
                else
                {
                    tp[j]=0;
                }
            }
            ans=max(ans,maxRectangleArea(tp));
        }
        return ans;
    }
};