//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int st,int end,int arr[],vector<vector<int>> &dp)
    {
        if(st>=end)
        {
            return 0;
        }
        if(dp[st][end]!=-1)
            return dp[st][end];
        if(1)
        {
            int val=INT_MAX;
            for(int i=st;i<end;i++)
            {
                int temp=solve(st,i,arr,dp)+solve(i+1,end,arr,dp)+(arr[st-1]*arr[i]*arr[end]);
                val=min(val,temp);
            }
            dp[st][end]=val;
        }
        return dp[st][end];
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        int n=N;
        vector<vector<int>> dp(n+100,vector<int>(n+100,-1));
        return solve(1,N-1,arr,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends