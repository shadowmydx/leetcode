class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        TreeNode *head = root;
        stack<TreeNode *> stk;
        vector<int> res;
        while (root || !stk.empty())
        {
            if (root)
            {
                stk.push(root);
                root = root->left;
            }
            else if (!root && !stk.empty())
            {
                root = stk.top();
                stk.pop();
                res.push_back(root->val);
                root = root->right;
            }
        }
        return res;
    }
};