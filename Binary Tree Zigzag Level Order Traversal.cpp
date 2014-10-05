class Solution {
public:
   vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
    vector<vector<int> > res;
	vector<int> tmp;
	vector<int> heh;
	queue<TreeNode *> lev;
	queue<TreeNode *> dealed;
	int flag = 1;
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
		if (!flag)
		{
		    for (int i = tmp.size() - 1;i >= 0;i--)
		        heh.push_back(tmp[i]);
		}
		else
		{
		    for (int i = 0;i < tmp.size();i++)
		        heh.push_back(tmp[i]);
		}
		flag = !flag;
		res.push_back(heh);
	    tmp.clear();
	    heh.clear();
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
	return res;
    }
};