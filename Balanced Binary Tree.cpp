class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if (_isBalanced(root) != -1)
            return true;
        return false;
    }
    int _isBalanced(TreeNode *root) // 若是平衡树则返回树高，否则返回-1
    {
        if (root == NULL)
            return 0;
        int sum1 = _isBalanced(root->left);
        int sum2 = _isBalanced(root->right);
        if (sum1 != -1 && sum2 != -1)
        {
            int sum = sum1 - sum2;
            sum = sum > 0 ? sum : -sum;
            if (sum <= 1)
            {
                return sum1 > sum2 ? sum1 + 1 : sum2 + 1;
            }
        }
        return -1;
    }
    
};