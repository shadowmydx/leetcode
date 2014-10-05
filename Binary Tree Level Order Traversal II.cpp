class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
    vector<vector<int> > res;
    vector<vector<int> > hoo;
	vector<int> tmp;
	queue<TreeNode *> lev;
	queue<TreeNode *> dealed;
	if (root) lev.push(root);
	while (!lev.empty())
	{
		while (!lev.empty())
		{
			TreeNode *head = lev.front();
			tmp.push_back(head->val);
			lev.pop();
			dealed.push(head);
		}
		res.push_back(tmp);
	    tmp.clear();
		while (!dealed.empty())
		{
			TreeNode *head = dealed.front();
			if (head->left)
				lev.push(head->left);
			if (head->right)
				lev.push(head->right);
			dealed.pop();
		}		
	}
	for (int i = res.size() - 1;i >= 0;i --)
	{
	    hoo.push_back(res[i]);
	}
	return hoo;
    }
};