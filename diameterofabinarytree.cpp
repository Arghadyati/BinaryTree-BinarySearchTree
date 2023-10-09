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

int maxheight(Node *root, int &diameter)
{
    if (root == NULL)
        return 0;
    int lh = maxheight(root->left, diameter);
    int rh = maxheight(root->right, diameter);
    diameter = max(diameter, lh + rh);
    return 1 + max(lh, rh);
}
int diameterOfBinaryTree(Node *root)
{
    int diameter = 0;
    maxheight(root, diameter);
    return diameter;
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
    root->right->left->left->left = new Node(9);
    root->right->right->right = new Node(7);
    root->right->right->right->right = new Node(8);
    int diameter = 0;
    maxheight(root, diameter);
    int dia = diameterOfBinaryTree(root);
    cout << "Diameter of the bianry tree is : " << dia << endl;
}