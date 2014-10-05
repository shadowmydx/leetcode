class Solution {
public:
    int minDepth(TreeNode *root) {
        if (root == NULL)
            return 0;
        int num1 = minDepth(root->left);
        int num2 = minDepth(root->right);
        if (num1 == 0 && num2 == 0)
            return 1;
        else if (num1 == 0 && num2 != 0)
            return num2 + 1;
        else if (num1 != 0 && num2 == 0)
            return num1 + 1;
        return num1 < num2 ? num1 + 1 : num2 + 1;
    }
};