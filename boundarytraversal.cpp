#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *right, *left;
    node(int val)
    {
        this->data = val;
        right = left = NULL;
    }
};
bool isleaf(node *root)
{
    return (root->left == NULL && root->right == NULL);
}
void addleft(node *root, vector<int> &res)
{
    node *curr = root->left;
    while (curr)
    {
        if (!isleaf(curr))
            res.push_back(curr->data);
        if (curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
}
void addright(node *root, vector<int> &res)
{
    node *curr = root->right;
    vector<int> temp;
    while (curr)
    {
        if (!isleaf(curr))
            temp.push_back(curr->data);
        if (curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }
    for (int i = temp.size() - 1; i >= 0; i--)
    {
        res.push_back(temp[i]);
    }
}
void addleaf(node *root, vector<int> &res)
{
    if (isleaf(root))
    {
        res.push_back(root->data);
        return;
    }
    if (root->left)
        addleaf(root->left, res);
    if (root->right)
        addleaf(root->right, res);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    node *root = new node(1);
    root->left = new node(2);
    root->left->left = new node(3);
    root->left->left->right = new node(4);
    root->left->left->right->left = new node(5);
    root->left->left->right->right = new node(6);
    root->right = new node(7);
    root->right->right = new node(8);
    root->right->right->left = new node(9);
    root->right->right->left->left = new node(10);
    root->right->right->left->right = new node(11);
    vector<int> res;
    if (!isleaf(root))
        res.push_back(root->data);
    addleft(root, res);
    addleaf(root, res);
    addright(root, res);
    for (auto it : res)
    {
        cout << it << " ";
    }
}