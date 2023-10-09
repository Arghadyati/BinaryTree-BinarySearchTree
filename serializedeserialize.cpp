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
string serialize(TreeNode *root)
{
    if (!root)
        return "";
    string s = "";
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();
        if (curr == NULL)
            s.append("#,");
        else
            s.append(to_string(curr->val) + ',');
        if (curr != NULL)
        {
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    return s;
}

TreeNode *deserialize(string data)
{
    if (data.size() == 0)
        return NULL;
    stringstream s(data);
    string str;
    getline(s, str, ',');
    TreeNode *root = new TreeNode(stoi(str));
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {

        TreeNode *node = q.front();
        q.pop();

        getline(s, str, ',');
        if (str == "#")
        {
            node->left = NULL;
        }
        else
        {
            TreeNode *leftNode = new TreeNode(stoi(str));
            node->left = leftNode;
            q.push(leftNode);
        }

        getline(s, str, ',');
        if (str == "#")
        {
            node->right = NULL;
        }
        else
        {
            TreeNode *rightNode = new TreeNode(stoi(str));
            node->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(13);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    string op = serialize(root);
    TreeNode *ans = deserialize(op);
    cout << ans->val;
}