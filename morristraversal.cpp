#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int data)
	{
		this->val = data;
		left = right = NULL;
	}
};
vector<int> getInorder(TreeNode *root)
{
	vector<int> inorder;
	TreeNode *curr = root;
	while (curr != NULL)
	{
		if (curr->left == NULL)
		{
			inorder.push_back(curr->val);
			curr = curr->right;
		}
		else
		{
			TreeNode *prev = curr->left;
			while (prev->right && prev->right != curr)
			{
				prev = prev->right;
			}
			if (prev->right == NULL)
			{
				prev->right = curr;
				curr = curr->left;
			}
			else
			{
				prev->right = NULL;
				inorder.push_back(curr->val);
				curr = curr->right;
			}
		}
	}
	return inorder;
}
vector<int> getPreorder(TreeNode *root)
{
	vector<int> inorder;
	TreeNode *curr = root;
	while (curr != NULL)
	{
		if (curr->left == NULL)
		{
			inorder.push_back(curr->val);
			curr = curr->right;
		}
		else
		{
			TreeNode *prev = curr->left;
			while (prev->right && prev->right != curr)
			{
				prev = prev->right;
			}
			if (prev->right == NULL)
			{
				prev->right = curr;
				inorder.push_back(curr->val);
				curr = curr->left;
			}
			else
			{
				prev->right = NULL;
				curr = curr->right;
			}
		}
	}
	return inorder;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->left->right->right = new TreeNode(6);
	vector<int> ans = getInorder(root);
	for (auto it : ans)
	{
		cout << it << " ";
	}
	cout << endl;
	vector<int> ans2 = getPreorder(root);
	for (auto it : ans2)
	{
		cout << it << " ";
	}
	
	
}