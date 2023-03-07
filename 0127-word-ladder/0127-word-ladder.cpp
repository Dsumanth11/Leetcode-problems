class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> contains;
        for(auto x:wordList)
        {
            contains.insert(x);
        }
        if(contains.find(endWord)==contains.end())
            return 0;
        if(beginWord==endWord)
            return 1;
        set<string> visited;
        queue<string> qu;
        qu.push(beginWord);
        visited.insert(beginWord);
        int ans=1;
        while(!qu.empty())
        {
            int k=qu.size();
            while(k--)
            {
                auto x=qu.front();
                qu.pop();
                if(x==endWord)
                {
                    return ans;
                }
                for(int i=0;i<x.size();i++)
                {
//                     changing the ith character
                    char chbefore=x[i];
                    for(char tp='a';tp<='z';tp++)
                    {
                        x[i]=tp;
                        if(contains.find(x)!=contains.end() && visited.find(x)==visited.end())
                        {
                            visited.insert(x);
                            qu.push(x);
                        }
                    }
                    x[i]=chbefore;
                }
                
            }
            ans++;
        }
        return 0;
    }
};