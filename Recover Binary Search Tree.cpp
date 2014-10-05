class Solution {
public:
int MIN = 1 << 31;
int MAX = ~MIN;
int wro[2];
int top = 0;
vector<TreeNode *> node;
vector<int> number;
vector<int> tar;

void recoverTree(TreeNode *root)
{
	midOrder(root);
	sort(number.begin(),number.end());
	for (int i = 0;i < number.size();i++)
	{
		if (tar[i] != number[i])
			wro[top++] = i;
	}
	int tmp = node[wro[0]]->val;
	node[wro[0]]->val = node[wro[1]]->val;
	node[wro[1]]->val = tmp;
	top = 0;		
}

void midOrder(TreeNode *root)
{
	if (root == NULL)
		return;
	midOrder(root->left);
	tar.push_back(root->val);
	number.push_back(root->val);
	node.push_back(root);
	midOrder(root->right);
}
};