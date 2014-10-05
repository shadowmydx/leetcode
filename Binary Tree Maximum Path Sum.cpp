class Solution {
public:
    unordered_map<int,int> dict; // 记录计算过的rootmax的值
    int maxPathSum(TreeNode *root) {
        if (root == NULL)
            return (1 << 31);
        int num1 = rootMax(root);
        int num2 = maxPathSum(root->left);
        int num3 = maxPathSum(root->right);
        num1 = num1 > num2 ? num1 : num2;
        return num1 > num3 ? num1 : num3;
    }
    
    int rootMax(TreeNode *root)
    {
        int left  = rootOneWay(root->left);
        int right = rootOneWay(root->right);
        int tmp = 0;
        if (left >= 0 && right >= 0)
        {
            tmp = left + right;
        }
        else if (left >= 0 && right <= 0)
        {
            tmp = left;
        }
        else if (left <= 0 && right >= 0)
        {
            tmp = right;
        }
        else if (left <= 0 && right <= 0)
            tmp = 0;    
        return tmp + root->val;
    }
    
    int rootOneWay(TreeNode *root)
    {

        if (root == NULL)
            return (1 << 31);
        unordered_map<int,int> :: iterator it;
        it = dict.find((int)root);
        if (it != dict.end())
            return it->second;        
        int left  = rootOneWay(root->left);
        int right = rootOneWay(root->right);
        int tmp = 0;
        if (left >= 0 && right >= 0)
        {
            tmp = left > right ? left : right;
        }
        else if (left >= 0 && right <= 0)
        {
            tmp = left;
        }
        else if (left <= 0 && right >= 0)
        {
            tmp = right;
        }
        else if (left <= 0 && right <= 0)
            tmp = 0;
        dict[(int)root] = tmp + root->val;
        return tmp + root->val;
    }
};