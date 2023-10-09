#include<bits/stdc++.h>
using namespace std;
class node{
public:
	int data;
	node*left,*right;
	node(int val){
		this->data=val;
		left=right=NULL;
	}
};
void flatten(node * root) {
  if (root == NULL) return;
  stack < node * > st;
  st.push(root);
  while (!st.empty()) {
    node * cur = st.top();
    st.pop();

    if (cur -> right != NULL) {
      st.push(cur -> right);
    }
    if (cur -> left != NULL) {
      st.push(cur -> left);
    }
    if (!st.empty()) {
      cur -> right = st.top();
    }
    cur -> left = NULL;
  }

}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    node *root=new node(1);
    root->left=new node(2);
    root->right=new node(5);
    root->left->left=new node(3);
    root->left->right=new node(4);
    root->right->right=new node(6);
    root->right->right->left=new node(7);
    flatten(root);
    while(root->right!=NULL){
    	cout<<root->data<<"->";
    	root=root->right;
    }
    cout<<root->data;
}