// using inorder preorder
#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int data;
    TreeNode *left, *right;

    TreeNode(int val)
    {
        this->data = val;
        left = right = NULL;
    }
};
TreeNode *builder(vector<int> &preorder, int prestart, int preend, vector<int> &inorder, int instart, int inend, map<int, int> &map)
{
    if (prestart > preend || instart > inend)
        return NULL;
    TreeNode *root = new TreeNode(preorder[prestart]);
    int inroot = map[root->data];
    int numsleft = inroot - instart;
    root->left = builder(preorder, prestart + 1, prestart + numsleft, inorder, instart, inroot - 1, map);
    root->right = builder(preorder, prestart + numsleft + 1, preend, inorder, inroot + 1, inend, map);
    return root;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    map<int, int> map;
    for (int i = 0; i < inorder.size(); i++)
    {
        map[inorder[i]] = i;
    }
    TreeNode *root = builder(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, map);
    return root;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> preorder = {10, 20, 40, 50, 30, 60};
    vector<int> inorder = {40, 20, 50, 10, 60, 30};
    TreeNode *ans = buildTree(preorder, inorder);
    cout << ans->data;
}