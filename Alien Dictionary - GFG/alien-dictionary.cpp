//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string vc[], int n, int K) {
        //code hereint n;
        set<char> isPresent;
        for(int i=0;i<n;i++)
        {
            string x=vc[i];
            for(int j=0;j<x.size();j++)
            {
                isPresent.insert(x[j]);
            }
        }
        map<char,set<char>> mp;
        for(int i=1;i<n;i++)
        {
            bool chk=true;
            for(int j=0;j<min(vc[i].size(),vc[i-1].size());j++)
            {
                if(vc[i][j]!=vc[i-1][j])
                {
                    mp[vc[i-1][j]].insert(vc[i][j]);
                    break;
                }
            }
        }
        map<char,int> indegree;
        for(char ch='a';ch<='z';ch++)
        {
            indegree[ch]=0;
        }
        for(auto x:mp)
        {
            for(auto y:x.second)
            {
                indegree[y]++;
            }
        }
        string ans;
        queue<char> qu;
        for(char ch='a';ch<='z';ch++)
        {
            if(isPresent.find(ch)!=isPresent.end() && indegree[ch]==0)
            {
                qu.push(ch);
            }
        }
        while(!qu.empty())
        {
            auto x=qu.front();
            qu.pop();
            ans+=x;
            for(auto y:mp[x])
            {
                indegree[y]--;
                if(indegree[y]==0)
                {
                    qu.push(y);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends