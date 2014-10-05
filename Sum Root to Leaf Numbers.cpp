class Solution {
public:
    int sumNumbers(TreeNode *root) {
        int sum = 0;
        if (root)
            midOrder(root,sum,0);
        return sum;
    }
    void midOrder(TreeNode *root,int &sum,int val)
    {
        val *= 10;
        val += root->val;
        if (!root->left && !root->right)
            sum += val;
        if (root->left)
            midOrder(root->left,sum,val);
        if (root->right)
            midOrder(root->right,sum,val);
        
    }
};