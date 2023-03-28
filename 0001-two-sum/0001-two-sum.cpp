class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> arr;
        bool b=false;
        map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++)
        {
            int temp_sum=target-nums[i];
            if(mp.find(temp_sum)!=mp.end() && i!=mp[temp_sum])
            {
                arr.push_back(i);
                arr.push_back(mp[temp_sum]);
                break;
            }
        }
        return arr;
    }
};