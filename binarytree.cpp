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
            data = val;
            left = right = NULL;
        }
    };

    int main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        Node *root = new Node(1);
        root->left = new Node(5);
        root->right = new Node(6);
        root->left->right = new Node(7);
    }