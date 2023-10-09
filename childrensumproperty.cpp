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
void preorder(node *curr)
{
    if (curr == NULL)
        return;
    cout << curr->data << " ";
    preorder(curr->left);
    preorder(curr->right);
}
void reorder(node *root)
{
    if (root == NULL)
        return;
    int child = 0;
    if (root->left)
        child += root->left->data;
    if (root->right)
        child += root->right->data;
    if (child < root->data)
    {
        if (root->left)
            root->left->data = root->data;
        else if (root->right)
            root->right->data = root->data;
    }
    reorder(root->left);
    reorder(root->right);
    int tot = 0;
    if (root->left)
        tot += root->left->data;
    if (root->right)
        tot += root->right->data;
    if (root->left || root->right)
        root->data = tot;
}
void changeTree(node *root)
{
    reorder(root);
}

int main()
{

    node *root = new node(2);
    root->left = new node(35);
    root->left->left = new node(2);
    root->left->right = new node(3);
    root->right = new node(10);
    root->right->left = new node(5);
    root->right->right = new node(2);

    changeTree(root);
    preorder(root);

    return 0;
}