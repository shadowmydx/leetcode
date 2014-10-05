class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (!root)
            return true;
        TreeNode *head = (TreeNode *)malloc(sizeof(TreeNode));
        head->val = root->val;
        head->right = transform(root->left);
        if (isEqual(root->right,head->right))
            return true;
        return false;
    }
    bool isEqual(TreeNode *root1,TreeNode *root2)
    {
        if (!root1 || !root2)
        {
            if (!root1 && !root2)
                return true;
            return false;
        }
        if (root1->val != root2->val)
            return false;
        if (isEqual(root1->left,root2->left) && isEqual(root1->right,root2->right))
            return true;
        return false;
    }
    TreeNode *transform(TreeNode *root)
    {
        if (root == NULL)
            return NULL;
        TreeNode *tmp = root->left;
        root->left = transform(root->right);
        root->right = transform(tmp); // 上一轮中left的值已被改变
        return root;
    }
};