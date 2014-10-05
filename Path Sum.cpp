class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (!root)
            return false;
        if (root->left == NULL && root->right == NULL)
            if (root->val == sum)
                return true;
            else 
                return false;
        bool left = false,right = false;
        if (root->left)
            left = hasPathSum(root->left,sum - root->val);
        if (root->right)
            right = hasPathSum(root->right,sum - root->val);
        return left | right;
    }
};