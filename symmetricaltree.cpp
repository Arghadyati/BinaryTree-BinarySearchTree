#include<bits/stdc++.h>
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
bool issymmetrical(Node *left,Node *right){
  if(left==NULL||right==NULL)return(left==right);
  if(left->val!=right->val)return false;
  return issymmetrical(left->left,right->right)&&issymmetrical(left->right,right->left);
}
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
Node *root=new Node(1);
root->left=new Node(2);
root->right=new Node(2);
root->left->left=new Node(3);
root->left->right=new Node(4);
root->right->left=new Node(4);
root->right->right=new Node(3);
Node *node1=root->left;
Node *node2=root->right;
if(issymmetrical(node1,node2)){
    cout<<"Tree is symmetrical in nature ";
}
else{
    cout<<"Tree is not symetrical in nature ";
}
}