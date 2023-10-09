#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->data = val;
        left = right = NULL;
    }
};
int check(Node *root)
{
    if (root == NULL)
        return 0;
    int lh = check(root->left);
    if (lh == -1)
        return -1;
    int rh = check(root->right);
    if (rh == -1)
        return -1;
    if (abs(lh - rh) > 1)
        return -1;
    return 1 + max(lh, rh);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->left->left = new Node(4);
    root->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->right->right = new Node(7);
    root->right->right->right->right = new Node(8);
    int height = check(root);
    if (height == -1)
        cout << "The binary tree in not balanced." << endl;
    else
        cout << "The binary tree is balanced." << endl;
}