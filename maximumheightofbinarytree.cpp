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
int height(Node *root)
{
    if (root == NULL)
        return 0;
    int leftheight = height(root->left);
    int rightheight = height(root->right);
    return 1 + max(leftheight, rightheight);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(6);
    root->right->left->left = new Node(5);
    int ans = height(root);
    cout << "The height of the binary tree is : " << ans << endl;
}