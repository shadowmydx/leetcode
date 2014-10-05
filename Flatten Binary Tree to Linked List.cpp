class Solution {
public:
    void flatten(TreeNode *root) {
        if (root == NULL)
            return;
        TreeNode *tmp  = root->right;
        TreeNode *rptr = root; 
        flatten(root->left);
        root->right = root->left;
        root->left  = NULL;
        flatten(tmp);
        while (rptr->right != NULL)
            rptr = rptr->right;
        rptr->right = tmp;
    }
};