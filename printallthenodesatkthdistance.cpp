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
void markparents(node *root, node *target, unordered_map<node *, node *> &track)
{
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *curr = q.front();
        q.pop();
        if (curr->left)
        {
            track[curr->left] = curr;
            q.push(curr->left);
        }

        if (curr->right)
        {
            track[curr->right] = curr;
            q.push(curr->right);
        }
    }
}
vector<int> nodesatkthdistance(node *root, node *target, int k)
{
    unordered_map<node *, node *> track;
    markparents(root, target, track);
    unordered_map<node *, bool> visited;
    queue<node *> q;
    q.push(target);
    visited[target] = true;
    int curr = 0;
    while (!q.empty())
    {
        int size = q.size();
        if (curr++ == k)
            break;
        for (int i = 0; i < size; i++)
        {
            node *current = q.front();
            q.pop();
            if (current->left && !visited[current->left])
            {
                q.push(current->left);
                visited[current->left] = true;
            }
            if (current->right && !visited[current->right])
            {
                q.push(current->right);
                visited[current->right] = true;
            }
            if (track[current] && !visited[track[current]])
            {
                q.push(track[current]);
                visited[track[current]] = true;
            }
        }
    }
    vector<int> ans;
    while (!q.empty())
    {
        node *n = q.front();
        q.pop();
        ans.push_back(n->data);
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    node *root = new node(3);
    root->left = new node(5);
    root->right = new node(1);
    root->left->left = new node(6);
    root->left->right = new node(2);
    root->left->right->left = new node(7);
    root->left->right->right = new node(4);
    root->right->left = new node(6);
    root->right->right = new node(8);
    node *target = root->left;
    int k = 2;
    vector<int> op = nodesatkthdistance(root, target, k);
    for (auto it : op)
    {
        cout << it << " ";
    }
}