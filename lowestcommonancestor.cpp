#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *left, *right;
    Node(int val)
    {
        this->val = val;
        left = right = NULL;
    }
};
Node *lowestcommonancestor(Node *root, Node *p, Node *q)
{
    if (root == NULL || root == p || root == q)
    {
        return root;
    }
    Node *left = lowestcommonancestor(root->left, p, q);
    Node *right = lowestcommonancestor(root->right, p, q);
    if (left == NULL)
    {
        return right;
    }
    else if (right == NULL)
    {
        return left;
    }
    else
    {
        return root;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    root->right->left->left = new Node(8);
    root->right->right->left = new Node(6);
    root->right->right->right = new Node(7);
    Node *node1 = root->right->right->right;
    Node *node2 = root->right->left->left;
    Node *ans = lowestcommonancestor(root, node1, node2);
    cout << ans->val << endl;
}