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
TreeNode *builder(vector<int> &inorder, int is, int ie, vector<int> &postorder, int ps, int pe, map<int, int> &mp)
{
    if (is > ie || ps > pe)
    {
        return NULL;
    }
    TreeNode *root = new TreeNode(postorder[pe]);
    int inroot = mp[postorder[pe]];
    int numsleft = inroot - is;
    root->left = builder(inorder, is, inroot - 1, postorder, ps, ps + numsleft - 1, mp);
    root->right = builder(inorder, inroot + 1, ie, postorder, ps + numsleft, pe - 1, mp);
    return root;
}
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    map<int, int> mp;
    for (int i = 0; i < inorder.size(); i++)
    {
        mp[inorder[i]] = i;
    }
    TreeNode *root = builder(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, mp);
    return root;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> inorder = {40, 20, 50, 10, 60, 30};
    vector<int> postorder = {40, 50, 20, 60, 30, 10};
    TreeNode *ans = buildTree(inorder, postorder);
    cout << ans->val;
}