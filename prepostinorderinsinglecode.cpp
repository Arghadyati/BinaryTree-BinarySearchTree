#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int val)
    {
        this->data = val;
        left = right = NULL;
    }
};
void all(node *curr, vector<int> &in, vector<int> &pre, vector<int> &post)
{
    stack<pair<node *, int>> s;
    s.push({curr, 1});
    while (!s.empty())
    {
        auto it = s.top();
        s.pop();
        if (it.second == 1)
        {
            pre.push_back(it.first->data);
            it.second++;
            s.push(it);
            if (it.first->left != NULL)
                s.push({it.first->left, 1});
        }
        else if (it.second == 2)
        {
            in.push_back(it.first->data);
            it.second++;
            s.push(it);
            if (it.first->right != NULL)
                s.push({it.first->right, 1});
        }
        else
        {
            post.push_back(it.first->data);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(5);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right->left = new node(6);
    root->right->right = new node(7);
    vector<int> in, pre, post;
    all(root, in, pre, post);
    cout << "Inorder traversal is :";
    for (auto it : in)
    {
        cout << it << " ";
    }
    cout << endl;
    cout << "Preorder traversal is :";
    for (auto it1 : pre)
    {
        cout << it1 << " ";
    }
    cout << endl;
    cout << "Postorder traversal is :";
    for (auto it2 : post)
    {
        cout << it2 << " ";
    }
}