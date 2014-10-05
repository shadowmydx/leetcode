class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
	vector<int> res;
	vector<TreeNode*> mystk;
	while (root != NULL || !mystk.empty())
	{
		res.push_back(root->val);
		if (root->right)
			mystk.push_back(root->right);
		root = root->left;
		if (root == NULL && !mystk.empty())
		{
			root = mystk.back();
			mystk.pop_back();
		}
	}
	return res;
    }
};