#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left, *right;
    node(int val)
    {
        this->data = val;
        left = right = NULL;
    }
};
int leftheight(node *n)
{
    int height = 0;
    while (n)
    {

        height++;
        n = n->left;
    }
    return height;
}
int rightheight(node *n)
{
    int height = 0;
    while (n)
    {

        height++;
        n = n->right;
    }
    return height;
}
int countnodes(node *root)
{
    if (root == NULL)
        return 0;
    int lh = leftheight(root);
    int rh = rightheight(root);
    if (lh == rh)
        return (1 << lh) - 1;
    return 1 + countnodes(root->left) + countnodes(root->right);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->left->left = new node(8);
    root->left->left->right = new node(9);
    root->left->right->left = new node(10);
    root->left->right->right = new node(11);
    int ans = countnodes(root);
    cout << ans;
}