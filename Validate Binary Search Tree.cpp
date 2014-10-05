class Solution {
public:
    bool isValidBST(TreeNode *root) {
         if (root == NULL)
            return true;
         if (isValidBST(root->left) && isValidBST(root->right))
         {
             if (root->left && root->right)
             {
                 int max = findMax(root->left);
                 int min = findMin(root->right);
                 if (max < root->val && root->val < min)
                    return true;
                 return false;
             }
             else if (root->left && !root->right)
             {
                 int max = findMax(root->left);
                 if (root->val > max)
                    return true;
                 return false;
             }
             else if (!root->left && root->right)
             {
                 int min = findMin(root->right);
                 if (root->val < min)
                    return true;
                 return false;
             }
             else return true;
         }
         return false;
    }
    int findMin(TreeNode *root)
    {
        int num = 0;
        while (root)
        {
            num = root->val;
            root = root->left;
        }
        return num;
    }
    int findMax(TreeNode *root)
    {
        int num = 0;
        while (root)
        {
            num = root->val;
            root = root->right;
        }
        return num;
    }
};