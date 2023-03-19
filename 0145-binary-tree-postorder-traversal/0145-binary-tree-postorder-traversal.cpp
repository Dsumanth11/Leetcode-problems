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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk1,stk2;
        if(root!=NULL)
            stk1.push(root);
        while(!stk1.empty())
        {
            stk2.push(stk1.top());
            auto x=stk1.top();
            stk1.pop();
            if(x->left!=NULL)
            stk1.push(x->left);
            if(x->right!=NULL)
            stk1.push(x->right);
        }
        while(!stk2.empty())
        {
            ans.push_back(stk2.top()->val);
            stk2.pop();
        }
        return ans;
    }
};