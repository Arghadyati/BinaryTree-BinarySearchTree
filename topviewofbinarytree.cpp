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
void topview(Node * root,vector<int>&ans){
    queue<pair<Node*,int>>q;
    map<int,int>mpp;
    q.push({root,0});
    while(!q.empty()){
      auto it=q.front();
      Node *node=it.first;
      int line=it.second;
      q.pop();
      if(mpp.find(line)==mpp.end())mpp[line]=node->val;
      if(node->left){
        q.push({node->left,line-1});
      }
      if(node->right){
        q.push({node->right,line+1});
      }

    }

    for(auto it:mpp){
        ans.push_back(it.second);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    Node *root = new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->left->right->left=new Node(6);
    root->right->right=new Node(7);
    vector<int>ans;
    topview(root,ans);
    cout<<"The top view of the binary tree is : ";
    for(auto it:ans){
        cout<<it<<" ";
    }
   
}