class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tp;
        for(int i=0;i<nums.size();i++)
        {
            int ele=nums[i];
            auto it=lower_bound(tp.begin(),tp.end(),ele);
            if(it==tp.end())
            {
                tp.push_back(ele);
            }
            else
            {
                *it=ele;
            }
        }
        return tp.size();
    }
};