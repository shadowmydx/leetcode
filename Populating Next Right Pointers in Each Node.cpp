class Solution {
public:

void connect(TreeLinkNode *root)
{
	queue<TreeLinkNode *> dealed;
	queue<TreeLinkNode *> dealing;
if(root)	dealing.push(root);
	while (!dealing.empty())
	{
		TreeLinkNode *tmp = dealing.front();
		dealing.pop();
		dealed.push(tmp);
		if (dealing.empty())
		{
			tmp->next = NULL;
			while (!dealed.empty())
			{
				TreeLinkNode *p = dealed.front();
				dealed.pop();
				if (p->left)
					dealing.push(p->left);
				if (p->right)
					dealing.push(p->right);
			}
		}
		else
		{
			tmp->next = dealing.front();
		}	
	}
}
};