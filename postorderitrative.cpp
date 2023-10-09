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
void postOrderTrav(Node *curr, vector<int> &postOrder)
{

    stack<Node *> s1;
    stack<Node *> s2;
    s1.push(curr);
    while (!s1.empty())
    {
        curr = s1.top();
        s1.pop();
        s2.push(curr);
        if (curr->left != NULL)
            s1.push(curr->left);
        if (curr->right != NULL)
            s1.push(curr->right);
    }
    while (!s2.empty())
    {
        postOrder.push_back(s2.top()->data);
        s2.pop();
    }
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
    root->right->left = new Node(6);
    root->right->left->right = new Node(7);
    root->right->left->right->right = new Node(8);

    vector<int> postOrder;
    postOrderTrav(root, postOrder);

    cout << "The postOrder Traversal is : ";
    for (int i = 0; i < postOrder.size(); i++)
    {
        cout << postOrder[i] << " ";
    }
}