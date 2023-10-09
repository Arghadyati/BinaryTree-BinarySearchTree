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
  void inorder(node *curr){
    if(curr==NULL)return;
    inorder(curr->left);
    cout<<curr->data<<" ";
    inorder(curr->right);
  }
  int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    node *root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(7);
    root->right->right=new node(8);
    root->left->right->left=new node(6);
    root -> right -> right -> left = new node(9);
    root -> right -> right -> right = new node(10);
    inorder(root);

  }