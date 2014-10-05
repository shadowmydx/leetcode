class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        vector<int> number;
        vector<TreeNode *> res;
        for (int i = 0;i < n;i++)
            number.push_back(i + 1);
        buildTree(res,number,0,number.size());
        return res;
    }
    
    // left and right vec is the last call's vec to find a tree;
    void buildTree(vector<TreeNode *> &frompare,vector<int> &num,int start,int fin)
    {
        if (start >= fin)
        {
            frompare.push_back(NULL);
            return;
        }
        TreeNode *root;
        vector<TreeNode *> myleft;
        vector<TreeNode *> myright;
        for (int i = start;i < fin;i++)
        {
            int now = i;
            buildTree(myleft,num,start,i);
            buildTree(myright,num,i+1,fin);
            
            for (int i = 0;i < myleft.size();i++)
            {
                for (int j = 0;j < myright.size();j++)
                {
                    root   = (TreeNode *)malloc(sizeof(TreeNode)); // 'cause every tree has his rootnode...-3-
                    root->val = num[now];
                    root->left = myleft[i];
                    root->right = myright[j];
                    frompare.push_back(root);
                }
            }
            myright.clear();
            myleft.clear();
        }
    }
    
};