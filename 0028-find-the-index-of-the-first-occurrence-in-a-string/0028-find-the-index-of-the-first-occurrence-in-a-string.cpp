class Solution {
public:
    vector<int> prefixFunction(string s) {
        vector<int> p(s.size());
        int j = 0;
        for (int i = 1; i < (int)s.size(); i++) {
            while (j > 0 && s[j] != s[i])
                j = p[j-1];

            if (s[j] == s[i])
                j++;
            p[i] = j;
        }   
        return p;
    }
    int strStr(string haystack, string needle) {
        vector<int> lps=prefixFunction(needle);
        int crp=0;
        int cri=0;
        int crj=0;
        for(auto x:lps)
        {
            cout<<x<<" ";
        }
        cout<<"\n";
        while(cri<haystack.size())
        {
            if(crj==needle.size())
            {
                return cri-needle.size();
            }
            if(haystack[cri]==needle[crj])
            {
                cri++;
                crj++;
            }
            else
            {
                if(crj==0)
                {
                    cri++;
                }
                else
                {
                    crj=lps[crj-1];
                }
            }
        }
        if(crj==needle.size())
            return cri-needle.size();
        return -1;
    }
};