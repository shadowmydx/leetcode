class Solution {
public:
vector<int> postorderTraversal(TreeNode *root)
{
	vector<int> res;
	vector<TreeNode*>stk1;
	vector<TreeNode*>stk2;
    if(root)stk1.push_back(root);
	while (!stk1.empty())
	{
		root = stk1.back();
		stk1.pop_back();
		stk2.push_back(root);
		if (root->left != NULL && root->right != NULL)
		{
			stk1.push_back(root->left);
			stk1.push_back(root->right);
		}
		else if (root->left != NULL && root->right == NULL)
			stk1.push_back(root->left);
		else if (root->left == NULL && root->right != NULL)
			stk1.push_back(root->right);
	}
	while (!stk2.empty())
	{
		root = stk2.back();
		res.push_back(root->val);
		stk2.pop_back();
	}
	return res;
}

};