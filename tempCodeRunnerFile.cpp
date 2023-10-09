  #include<bits/stdc++.h>
  using namespace std;
  class node{
  public:
    int data;
    node *left;
    node* right;

    node(int val){
      this->data=val;
      left=right=NULL;
    }

  };
  void preorder(node *curr){
    if(curr==NULL)return;
    cout<<curr->data<<" ";
    preorder(curr->left);
    preorder(curr->right);