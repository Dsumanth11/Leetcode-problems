//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int makeProductOne(int arr[], int N) {
        // code here
        int ans=0;
        int neg=0;
        int zero=0;
        for(int i=0;i<N;i++)
        {
            if(arr[i]==0)
            {
                zero++;
            }
            else if(arr[i]>0)
            {
                ans+=arr[i]-1;
            }
            else
            {
                neg+=1;
                ans+=(-1)-(arr[i]);
            }
        }
        ans+=zero;
        if(neg%2==1 && zero==0)
        {
            ans+=2;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.makeProductOne(arr,N) << endl;
    }
    return 0;
}
// } Driver Code Ends