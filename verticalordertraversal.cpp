#include <bits/stdc++.h>
using namespace std;
class Treenode
{
public:
    int val;
    Treenode *left, *right;
    Treenode(int data)
    {
        this->val = data;
        left = right = NULL;
    }
};
void verticalorder(Treenode *root, vector<vector<int>> &ans)
{
    queue<pair<Treenode *, pair<int, int>>> todo;
    // first int denotes the vertical second int level 3 rd is the node present on the level
    map<int, map<int, multiset<int>>> nodes;
    todo.push({root, {0, 0}});
    while (!todo.empty())
    {
        auto p = todo.front();
        todo.pop();
        Treenode *node = p.first;
        int x = p.second.first;
        int y = p.second.second;
        nodes[x][y].insert(node->val);
        if (node->left)
            todo.push({node->left, {x - 1, y + 1}});
        if (node->right)
            todo.push({node->right, {x + 1, y + 1}});
    }

    for (auto p : nodes)
    {
        vector<int> col;
        for (auto q : p.second)
        {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    Treenode *root = new Treenode(1);
    root->left = new Treenode(2);
    root->right = new Treenode(3);
    root->left->left = new Treenode(4);
    root->left->right = new Treenode(10);
    root->left->left->right = new Treenode(5);
    root->left->left->right->right = new Treenode(6);
    root->right->left = new Treenode(9);
    root->right->right = new Treenode(10);
    vector<vector<int>> ans;
    verticalorder(root, ans);
    for (auto vctr : ans)
    {
        for (auto it : vctr)
        {
            cout << it << " ";
        }
    }
}