class Solution {
public:
    bool CheckSpeed(long long mid,vector<int> &piles,long long h)
    {
        long long cr=0;
        for(auto x:piles)
        {
            double hrs=x;
            hrs/=mid;
            cr+=ceil(hrs);
        }
        return cr<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long end=0;
        for(auto x:piles)
        {
            end+=x;
        }
        sort(piles.begin(),piles.end(),greater<int>());
        long long st=1;
        long long ans=end;
        while(st<=end)
        {
            long long mid=st+(end-st)/2;
            bool ispossible=CheckSpeed(mid,piles,h);
            if(ispossible)
            {
                ans=mid;
                end=mid-1;
            }
            else
            {
                st=mid+1;
            }
        }
        return (int)ans;
    }
};