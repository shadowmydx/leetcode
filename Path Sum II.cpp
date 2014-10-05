class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > res;
        vector<int> now;
        if (root == NULL)
            return res;
        countSum(root,now,res,sum);
        return res;
    }
    
    void countSum(TreeNode *root,vector<int> &now,vector<vector<int> > &res,int sum)
    {
        if (!root->left && !root->right)
        {
            if (root->val == sum)
            {
                now.push_back(root->val);
                res.push_back(now);
                now.pop_back(); // 这里需要弹出叶子节点
            }
        }
        if (root->left)
        {
            now.push_back(root->val);
            countSum(root->left,now,res,sum - root->val);
            now.pop_back(); // 注意：从左边出来需要弹出元素。
        }
        
        if (root->right)
        {
            now.push_back(root->val);
            countSum(root->right,now,res,sum - root->val);
            now.pop_back();
        }
        
    }
};