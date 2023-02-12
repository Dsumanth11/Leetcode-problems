//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int nums[], int n)  
	{  
	    // Your code goes here
	    vector<int> sumI;
    	for(int i=0;i<n;i++)
    	{
    		int cr=i;
    		int sum=INT_MIN;
    		for(int j=i-1;j>=0;j--)
    		{
    			if(nums[j]<nums[i])
    			{
    				if(sumI[j]>sum)
    				{
    					sum=sumI[j];
    					cr=j;
    				}
    			}
    		}
    		if(cr==i)
    		{
    			sumI.push_back(nums[cr]);
    		}
    		else
    		{
    			int tp=nums[i]+sum;
    			sumI.push_back(tp);
    		}
    // 		cout<<sumI[i]<<" ";
    // 		cout<<"\n";
    	}
    	return *max_element(sumI.begin(),sumI.end());
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends