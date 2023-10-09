#include <bits/stdc++.h>
using namespace std;
class Tree
{
public:
    int data;
    Tree *left;
    Tree *right;
    Tree(int val)
    {
        this->data = val;
        right = left = NULL;
    }
};
bool checkidentical(Tree *root1, Tree *root2)
{
    if (root1 == NULL || root2 == NULL)
    {
        return (root1 == root2);
    }
    return (root1->data == root2->data) && checkidentical(root1->left, root2->left) && checkidentical(root1->right, root2->right);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    Tree *root1 = new Tree(1);
    root1->left = new Tree(2);
    root1->right = new Tree(3);
    root1->right->left = new Tree(4);
    root1->right->right = new Tree(5);

    Tree *root2 = new Tree(1);
    root2->left = new Tree(2);
    root2->right = new Tree(3);
    root2->right->left = new Tree(4);
    root2->right->right = new Tree(5);

    if (checkidentical(root1, root2))
    {
        cout << "Identical tree" << endl;
    }
    else
    {
        cout << "Not identical tree" << endl;
    }
}