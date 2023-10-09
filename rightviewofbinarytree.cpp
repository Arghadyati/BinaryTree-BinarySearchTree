#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *left, *right;
    Node(int data)
    {
        this->val = data;
        left = right = NULL;
    }
};
void reversepreorder(Node *root,int level,vector<int>&ans){
  if(root==NULL)return;
  if(level==ans.size())ans.push_back(root->val);
  reversepreorder(root->right,level+1,ans);
  reversepreorder(root->left,level+1,ans);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    Node *root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->left->right->left=new Node(6);
    root->right->right=new Node(7);
    vector<int>ans;
    reversepreorder(root,0,ans);
    for(auto it :ans)cout<<it<<" ";
}