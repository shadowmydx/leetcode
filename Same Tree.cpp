class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (!p && !q)
            return true;
        if ((!p && q) || (p && !q))
            return false;
        if (isSameTree(p->left,q->left) && isSameTree(p->right,q->right))
        {
            return p->val == q->val ? true : false;
        }
        return false;
    }
};