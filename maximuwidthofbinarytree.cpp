#include <bits/stdc++.h>
#define lli long long int
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
// int maximumwidth(Node *root)
// {
// if (!root)
//     return 0;
// queue<pair<Node *, int>> q;
// q.push({root, 0});
// int ans = 0;
// while (!q.empty())
// {
//     int size = q.size();
//     int min = q.front().second;
//     int first, last;
//     for (int i = 0; i < size; i++)
//     {
//         int curr_id = q.front().second - min;
//         Node *node = q.front().first;
//         q.pop();
//         if (i == 0)
//             first = curr_id;
//         if (i == size - 1)
//             last = curr_id;
//         if (node->left)
//             q.push({node->left, curr_id * 2 + 1});
//         if (node->right)
//             q.push({node->right, curr_id * 2 + 2});
//     }
//     ans = max(ans, last - first + 1);
// }
// return ans;
//}
int widthOfBinaryTree(Node *root)
{
    if (!root)
        return 0;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    lli ans = 0;
    while (!q.empty())
    {
        lli size = q.size();
        lli min = q.front().second;
        lli first, last;
        for (int i = 0; i < size; i++)
        {
            lli curr_id = q.front().second;
            Node *node = q.front().first;
            q.pop();
            if (i == 0)
                first = curr_id;
            if (i == size - 1)
                last = curr_id;
            if (node->left)
                q.push({node->left, curr_id * 2 + 1});
            if (node->right)
                q.push({node->right, curr_id * 2 + 2});
        }
        ans = max(ans, last - first + 1);
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    Node *root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(8);
    root->right->right = new Node(4);
    int ans = widthOfBinaryTree(root);
    cout << ans << endl;
}