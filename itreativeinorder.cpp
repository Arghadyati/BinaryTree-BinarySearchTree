#include<bits/stdc++.h>
using namespace std;
class Node{
public:
	int data;
	Node *left;
	Node *right;
	Node(int val){
		this->data=val;
		left=right=NULL;
	}

};
void inorder(Node *root,vector<int>&in){
	Node *node=root;
	stack<Node*>s;
	while(true){
	if(node!=NULL){
		s.push(node);
		node=node->left;
	}
	else{
		if(s.empty()==true)break;
		node=s.top();
		s.pop();
		in.push_back(node->data);
		node=node->right;
	}
	}
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    Node *root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->left->right->left=new Node(6);
    root->left->right->right=new Node(7);
    vector<int>in;
    inorder(root,in);
    for(auto it:in){
    	cout<<it<<" ";
    }
}