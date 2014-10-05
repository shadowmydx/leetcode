class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        TreeNode *root = balancedBst(num,0,num.size() - 1);
        return root;
    }
    TreeNode *balancedBst(vector<int> &num,int start,int fin)
    {
        if (start <= fin)
        {
            int mid = (start + fin) / 2;
            TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
            root->val = num[mid];
            root->left = balancedBst(num,start,mid-1);
            root->right = balancedBst(num,mid+1,fin);
            return root;
        }
        return NULL;
    }
};