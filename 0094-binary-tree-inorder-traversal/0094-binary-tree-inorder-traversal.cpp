/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk;
        if(!root)
            return ans;
        stk.push(root);
        while(!stk.empty())
        {
            auto x=stk.top();
            if(x==NULL)
            {
                stk.pop();
                if(!stk.empty())
                {
                    ans.push_back(stk.top()->val);
                    x=stk.top();
                    stk.pop();
                    stk.push(x->right);
                }
            }
            else
            {
                stk.push(x->left);
            }
        }
        return ans;
    }
};