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
void zigzagtraversal(node *root, vector<vector<int>> &ans)
{
    if (root == NULL)
    {
        return;
    }
    queue<node *> q;
    q.push(root);
    bool ltr = true;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> row(size);
        for (int i = 0; i < size; i++)
        {
            node *n = q.front();
            q.pop();
            int ind = (ltr) ? i : (size - 1 - i);
            row[ind] = n->data;
            // row.push_back(n->data);

            if (n->left)
            {
                q.push(n->left);
            }
            if (n->right)
            {
                q.push(n->right);
            }
            //  if(!ltr){
            //     reverse(row.begin(),row.end());

            // }
        }
        ltr = !ltr;
        // row.erase( remove( row.begin(), row.end(), 0 ), row.end() ) ;
        ans.push_back(row);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(6);
    vector<vector<int>> ans;
    zigzagtraversal(root, ans);
    for (auto vctr : ans)
    {
        for (auto it : vctr)
        {
            cout << it << " ";
        }
    }
}