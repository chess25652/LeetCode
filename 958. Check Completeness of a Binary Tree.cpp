/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:

	bool isCompleteTree(TreeNode* root)
	{
		int a, b;
		return(isComplete(root, a, b));
	}
	bool isComplete(TreeNode* root, int &max, int& min)
	{
		if (root == nullptr)
		{
			min = 0;
			max = 0;
			return true;
		}
		int a, b, c, d;
		if (isComplete(root->left, a, b) && isComplete(root->right, c, d))
		{
			max = (a > c ? a : c) + 1;
			min = (b < d ? b : d) + 1;
			if (a == b)
			{
				if (b == c)
					return (c == d || c == d + 1);
				else if (b == c + 1)
					return (c == d);
				else
					return false;
			}
			else if (a == b + 1)
				return (b == c && c == d);
			else
				return false;
		}
		else
			return false;
	}
};