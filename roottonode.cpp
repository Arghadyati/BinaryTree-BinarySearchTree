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
bool roottonode(Node *root, vector<int> &arr, int x)
{
    if (!root)
        return false;
    arr.push_back(root->val);
    if (root->val == x)
        return true;
    if (roottonode(root->left, arr, x) || roottonode(root->right, arr, x))
        return true;
    arr.pop_back();
    return false;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);
    vector<int> arr;
    roottonode(root, arr, 7);
    for (auto it : arr)
    {
        cout << it << " ";
    }
}