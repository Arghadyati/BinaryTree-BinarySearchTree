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
node *findTarget(node *root, int start)
{
    if (root == NULL)
        return NULL;
    if (root->data == start)
        return root;
    return findTarget(root->left, start);
    return findTarget(root->right, start);
}
void markparents(unordered_map<node *, node *> &parent, node *root, node *target)
{
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *curr = q.front();
        q.pop();
        if (curr->left)
        {
            parent[curr->left] = curr;
            q.push(curr->left);
        }
        if (curr->right)
        {
            parent[curr->right] = curr;
            q.push(curr->right);
        }
    }
}
int burnbinary(node *root, node *target)
{
    unordered_map<node *, node *> parent;
    unordered_map<node *, bool> visited;
    markparents(parent, root, target);
    queue<node *> q;
    q.push(target);
    int maxi = 0;
    visited[target] = true;
    while (!q.empty())
    {
        int fl = 0;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            node *front = q.front();
            q.pop();
            if (front->left && !visited[front->left])
            {
                q.push(front->left);
                visited[front->left] = true;
                fl = 1;
            }
            if (front->right && !visited[front->right])
            {
                q.push(front->right);
                visited[front->right] = true;
                fl = 1;
            }
            if (parent[front] && !visited[parent[front]])
            {
                q.push(parent[front]);
                visited[parent[front]] = true;
                fl = 1;
            }
        }
        if (fl)
            maxi++;
    }
    return maxi;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->left->right = new node(7);
    root->right->left = new node(5);
    root->right->right = new node(6);
    node *targett = findTarget(root, 2);
    int ans = burnbinary(root, targett);
    cout << ans;
}